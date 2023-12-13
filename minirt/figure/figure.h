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
t_sphere	sphere(t_coord center, double radius);
float		hit_sphere(t_sphere *sp, t_ray *ray);
#endif