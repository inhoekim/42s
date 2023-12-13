/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_func3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:56:15 by seykim            #+#    #+#             */
/*   Updated: 2023/12/14 06:17:57 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

float	vec_len(t_vector vec)
{
	return ((float)sqrtf(vec_len_sqr(vec)));
}

float	vec_len_sqr(t_vector vec)
{
	float	num;

	num = (vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z);
	return (num);
}

t_vector	vec_unit(t_vector vec)
{	
	float		len;

	len = vec_len(vec);
	return (vec_div_num(vec, len));
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