/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:38:21 by inhkim            #+#    #+#             */
/*   Updated: 2023/12/14 04:02:16 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VIEW_H
# define VIEW_H
# include "../minirt.h"

t_camera	init_camera(t_coord origin, t_vector dir);
t_ray		ray(t_coord origin, t_vector vec);
t_vector	ray_at(t_ray *ray, float t);
t_ray		ray_primary(t_camera *cam, float u, float v);
t_vector	ray_color(t_ray *ray, t_sphere *sphere);
#endif