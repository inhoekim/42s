/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:41:43 by inhkim            #+#    #+#             */
/*   Updated: 2023/12/14 06:08:32 by inhkim           ###   ########.fr       */
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
	t_vector	pixel_vec;
	t_coord		pixel_coord;
	
	// left_bottom + x * horizontal + y * vertical - origin 의 단위 벡터.
	pixel_coord = vec_add(vec_mul_num(cam->horizon_vec, x), \
	vec_mul_num(cam->vertical_vec, y));
	pixel_coord = vec_add(pixel_coord, cam->left_bottom); // temp_vec = 현재 픽셀의 좌표값
	pixel_vec = vec_sub(pixel_coord, cam->origin); // 현재 픽셀의 좌표와 카메라의 좌표를 빼서 벡터를 만든다
	return (ray(cam->origin, pixel_vec));
}

//광선이 최종적으로 얻게된 픽셀의 색상 값을 리턴.
t_vector	ray_color(t_ray *ray, t_sphere *sphere)
{
	float		num;
	float		t;
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
