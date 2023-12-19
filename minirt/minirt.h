/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:37:15 by inhkim            #+#    #+#             */
/*   Updated: 2023/12/19 20:34:04 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define FALSE 0
# define TRUE 1
# define INF 987654321
# define WIDTH 400
# define HEIGHT 400

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "util/get_next_line.h"

// typedef struct s_obj_list;
// typedef struct s_triple;
// typedef struct s_info;
// typedef struct s_light;
// typedef struct s_alight;
// typedef struct s_camera;
// typedef struct s_cylinder;
// typedef struct s_cylinder_float;

enum e_figure
{
	SPHERE = 1,
	PLANE = 2,
	CYLINDER = 3,
	AMBIENT_LIGHTNING = 4,
	CAMERA = 5,
	LIGHT = 6
};

typedef struct s_triple
{
	float	x;
	float	y;
	float	z;
}	t_triple;

typedef struct s_triple	t_vector;
typedef struct s_triple	t_coord;
typedef int				t_bool;

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

typedef struct s_light
{
	float		ratio;
	t_coord		origin;
	t_triple	color;
}	t_light;

typedef struct s_alight
{
	float		ratio;
	t_triple	color;
}	t_alight;

typedef struct s_info
{
	t_camera	cam;
	t_light		light;
	t_alight	a_light;
	int			cam_num;
	int			light_num;
	int			a_light_num;
}	t_info;

typedef struct s_cylinder_float
{
	float		delimeter;
	float		height;
} t_cylinder_float;

typedef struct s_cylinder
{
	t_coord				origin;
	t_cylinder_float	num;
	t_triple			color;
	t_vector			cy_vec;
}	t_cylinder;

typedef struct s_plane
{
	t_coord		origin;
	t_triple	color;
	t_vector	pl_vec;
}	t_plane;




typedef struct s_ray
{
	t_coord		origin;
	t_vector	dir_vec;
}	t_ray;

typedef struct s_sphere
{
	t_coord		center;
	t_triple	color;
	float		radius;
}	t_sphere;

typedef struct s_hit
{
	t_coord		coord;
	t_vector	normal_vec;
	float		t_min;
	float		t_max;
	float		t;
	t_bool		front_face;
	t_triple	albedo;
}	t_hit;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_data		data;
}	t_mlx;

typedef struct s_obj_list
{
	int			type;
	t_triple	albedo;
	void		*data;
	void		*next;
}	t_obj_list;


typedef struct s_obj_list t_ptr;

int		create_trgb(int t, int r, int g, int b);
void	print_error(char *str);
#endif
