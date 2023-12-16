/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:37:15 by inhkim            #+#    #+#             */
/*   Updated: 2023/12/16 16:43:15 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define FALSE 0
# define TRUE 1
# define INF 987654321
# define WIDTH 300
# define HEIGHT 600
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
	t_vector	dir;
	t_vector	vertical_vec;
	t_vector	horizon_vec;
	float		focal_len;
	float		fov;
}	t_camera;
typedef struct s_sphere
{
	t_coord	center;
	float	radius;
}	t_sphere;
typedef struct s_hit
{
	t_coord		coord;
	t_vector	normal_vec;
	float		t_min;
	float		t_max;
	float		t;
	t_bool		front_face;
}	t_hit;
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;
typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_data		image;
}	t_vars;
#endif
