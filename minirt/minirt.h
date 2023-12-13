/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:37:15 by inhkim            #+#    #+#             */
/*   Updated: 2023/12/14 04:05:05 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define FALSE 0
# define TRUE 1

typedef struct s_triple
{
	float	x;
	float	y;
	float	z;
}	t_triple;
typedef struct s_triple	t_vector;
typedef struct s_triple	t_coord;
typedef int				t_bool;
typedef struct s_ray
{
	t_coord		origin;
	t_vector	dir_vec;
}	t_ray;
typedef struct s_camera
{
	t_coord		origin;
	t_coord		left_bottom;
	t_vector	horizon_vec;
	t_vector	vertical_vec;
	float		focal_len;
	float		viewport_h;
	float		viewport_w;
}	t_camera;
typedef struct s_canvas
{
	int		width;
	int		height;
	float	aspect_ratio;
}	t_canvas;
typedef struct s_sphere
{
	t_coord	center;
	float	radius;
}	t_sphere;
#endif
