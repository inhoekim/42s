/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:38:21 by inhkim            #+#    #+#             */
/*   Updated: 2023/12/13 23:48:08 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# include "../vector/vector.h"
#endif
#ifndef VIEW_H
# define VIEW_H

typedef struct s_triple
{
	int	x;
	int	y;
	int	z;
}	t_triple;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	dir_vec;
}	t_ray;

typedef struct s_camera
{
	t_vector	origin;
	t_vector	horizon_vec;
	t_vector	vertical_vec;
	t_vector	left_bottom;
	float		focal_len;
	float		viewport_h;
	float		viewport_w;
}	t_camera;

typedef struct s_canvas
{
	int		width;
	int		height;
	float	aspect_ratio; //종횡비
}	t_canvas;


t_camera	init_camera(t_canvas *canvas, t_vector origin);
t_canvas	init_canvas(int width, int height);
t_ray		ray(t_vector origin, t_vector dir_vec);
t_vector	ray_at(t_ray *ray, float t);
t_ray		ray_primary(t_camera *cam, float u, float v);
t_vector	ray_color(t_ray *r);
#endif