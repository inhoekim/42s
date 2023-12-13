/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:41:43 by inhkim            #+#    #+#             */
/*   Updated: 2023/12/14 03:23:51 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"
#include "../vector/vector.h"

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
	t_vector	temp_vec;
	
	// left_bottom + x * horizontal + y * vertical - origin 의 단위 벡터.
	temp_vec = vec_add(vec_mul_num(cam->horizon_vec, x), \
	vec_mul_num(cam->vertical_vec, y));
	temp_vec = vec_add(temp_vec, cam->left_bottom); // temp_vec = 현재 픽셀의 좌표값
	temp_vec = vec_sub(temp_vec, cam->origin); // temp_vec = 현재 픽셀의 좌표와 카메라의 좌표를 빼서 벡터를 만든다
	return (ray(cam->origin, temp_vec));
}

//광선이 최종적으로 얻게된 픽셀의 색상 값을 리턴.
t_vector	ray_color(t_ray *r)
{
    float  t;

    t = 0.5 * (r->dir_vec.y + 1.0);
    // (1-t) * 흰색 + t * 하늘색
    return (vec_add(vec_mul_num(vec(1, 1, 1), 1.0 - t), vec_mul_num(vec(0.5, 0.7, 1.0), t)));
}
