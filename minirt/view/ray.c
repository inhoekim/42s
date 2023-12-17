/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:41:43 by inhkim            #+#    #+#             */
/*   Updated: 2023/12/16 18:57:07 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"
#include "../vector/vector.h"
#include "../figure/figure.h"

//ray 생성자(정규화 된 ray)
t_ray	ray(t_coord origin, t_vector vec)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir_vec = vec_unit(vec);
	return (ray);
}

//ray origin point 부터 방향벡터 ray dir * t 만큼 떨어진 점.
t_coord	ray_at(t_ray *ray, float t)
{
	return (vec_add(ray->origin, vec_mul_num(ray->dir_vec, t)));
}

t_ray	ray_primary(t_camera *cam, float x, float y)
{
	t_vector	ray_vec;
	t_coord		destination;
	
	destination = vec_add(vec_add(cam->left_bottom, x), y);
	ray_vec = vec_sub(destination, cam->origin); // 현재 픽셀의 좌표와 카메라의 좌표를 빼서 벡터를 만든다
	return (ray(cam->origin, ray_vec));
}

//광선이 최종적으로 얻게된 픽셀의 색상 값을 리턴.
t_vector	ray_color(t_ray *ray, t_sphere *sphere)
{
	float		num;
	t_hit		hit;

	hit.t_min = 0;
	hit.t_max = INF;
	if (hit_sphere(sphere, ray, &hit))
	{
		return (vec_mul_num(vec_add(hit.normal_vec, vec(1, 1, 1)), 0.5));
	}
	num = 0.5 * (ray->dir_vec.y + 1.0);
	return (vec_add(vec_mul_num(vec(1, 1, 1), 1.0 - num), vec_mul_num(vec(0.5, 0.7, 1.0), num)));
}

static void raytracing(t_scene *scene, t_mlx *mlx)
{
	int     i; // x
	int     j; // y
	t_color3    pixel_color;

	j = HEIGHT - 1;
	while (j >= 0)
	{
		i = 0;
	   while (i < WIDTH)
		{
			printf ("x : %d y : %d\n", i, j);
			scene->ray = ray_primary(&scene->camera, i, j); // 광선의 방향 벡터가 정해진다.
			print_vec(scene->ray.dir); // 확인을 위한 출력 코드.
			pixel_color = ray_color(scene); // 광선을 발사하여 물체와 충돌 유무에 따라 색이 변한다.
			my_mlx_pixel_put(mlx, i, HEIGHT - 1 - j, create_trgb(0, pixel_color.x, pixel_color.y, pixel_color.z));
			// 위쪽에서부터 찍을 것이기에 높이에서 빼줌.
			++i;
		}
		--j;
	}
}