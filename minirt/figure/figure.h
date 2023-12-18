/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:08:42 by inhkim            #+#    #+#             */
/*   Updated: 2023/12/14 06:08:54 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURE_H
# define FIGURE_H
# include "../minirt.h"
void		*sphere(t_coord center, double radius);
t_bool	    hit_sphere(t_sphere *sp, t_ray *ray, t_hit *hit);
t_obj_list  *object(int type, void *data);
void        obj_add(t_obj_list **lst, t_obj_list *new_element);
t_obj_list  *obj_last(t_obj_list *lst);
t_bool      hit(t_obj_list *world, t_ray *ray, t_hit *hit);
t_bool      hit_obj(t_obj_list *world, t_ray *ray, t_hit *hit);
#endif