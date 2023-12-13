/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:46:35 by inhkim            #+#    #+#             */
/*   Updated: 2023/12/14 03:21:26 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# include "../minirt.h"
#endif
#ifndef VECTOR_H
# define VECTOR_H
# include <stdio.h>
# include <math.h>

t_vector	vec(float x, float y, float z);
t_vector	vec_add(t_vector a, t_vector b);
t_vector	vec_sub(t_vector a, t_vector b);
t_vector	vec_mul(t_vector a, t_vector b);
t_vector	vec_div(t_vector a, t_vector b);
t_vector	vec_mul_num(t_vector a, float num);
t_vector	vec_cross_product(t_vector a, t_vector b);
t_vector	vec_div_num(t_vector a, float num);
t_vector	vec_unit(t_vector vec);
float		vec_dot_product(t_vector a, t_vector b);
float		vec_len(t_vector vec);
float		vec_len_sqr(t_vector vec);
void		vec_set(t_vector *vec, float x, float y, float z);

#endif