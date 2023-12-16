/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_func3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:56:15 by seykim            #+#    #+#             */
/*   Updated: 2023/12/16 18:26:17 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

float	vec_len(t_vector vec)
{
	return (sqrtf(vec_len_square(vec)));
}

float	vec_len_square(t_vector vec)
{
	return ((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
}

t_vector	vec_unit(t_vector vec)
{	
	return (vec_div_num(vec, vec_len(vec)));
}

void	vec_set(t_vector *vec, float x, float y, float z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

t_vector	vec(float x, float y, float z)
{
	t_vector	new_vec;

	new_vec.x = x;
	new_vec.y = y;
	new_vec.z = z;
	return (new_vec);
}