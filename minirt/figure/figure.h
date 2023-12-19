/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:08:42 by inhkim            #+#    #+#             */
/*   Updated: 2023/12/19 20:09:25 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURE_H
# define FIGURE_H

# include "../minirt.h"

void				*sphere(t_coord center, t_triple color, double radius);
void				*cylinder(t_coord origin, t_triple color, t_vector dir, t_cylinder_float num);
t_cylinder_float	cylinder_float(float x, float y);
void				*plane(t_coord origin, t_triple color, t_vector dir);
t_bool	    		hit_sphere(t_sphere *sp, t_ray *ray, t_hit *hit);
t_obj_list  		*object(int type, void *data, t_triple albedo);
void    		    obj_add(t_obj_list **lst, t_obj_list *new_element);
t_obj_list			*obj_last(t_obj_list *lst);
t_bool  		    hit(t_obj_list *world, t_ray *ray, t_hit *hit);
t_bool				hit_obj(t_obj_list *world, t_ray *ray, t_hit *hit);
t_light				*light_point(t_coord light_origin, t_triple color, float ration);

#endif