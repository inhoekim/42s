/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:44:50 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/28 15:44:51 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_all_clear(t_vector *vec)
{
	int	idx;

	idx = -1;
	while (++idx < vec->size)
		free(vec->inner_vec[idx].str);
	vec->size = 0;
}

void	ft_str_copy(char *dest, \
char *src, long long start, long long end)
{
	long long	dest_idx;
	long long	src_idx;

	dest_idx = 0;
	src_idx = start;
	while (src_idx != end)
	{
		dest[dest_idx] = src[src_idx];
		dest_idx++;
		src_idx++;
	}
	dest[dest_idx] = '\0';
}

int	ft_split_newline(t_vector *vec, \
int idx, long long offset, char **ret_str)
{
	char		*str;

	str = vec->inner_vec[idx].str;
	*ret_str = (char *)malloc(sizeof(char) * ((offset + 1) + 1));
	if (*ret_str == FT_NULL)
		return (FT_ERR);
	ft_str_copy(*ret_str, str, 0, offset + 1);
	ft_str_copy(str, str, offset + 1, vec->inner_vec[idx].size);
	vec->inner_vec[idx].size = vec->inner_vec[idx].size - (offset + 1);
	if (vec->inner_vec[idx].size == 0)
	{
		free(vec->inner_vec[idx].str);
		vec->inner_vec[idx].str = FT_NULL;
	}
	return (FT_TRUE);
}

int	ft_expand_vector(t_vector *vec)
{
	char		*temp;
	int			idx;

	temp = vec->str;
	if (temp)
		vec->capacity = vec->capacity * 2;
	vec->str = (char *)malloc(sizeof(char) * (vec->capacity));
	if (vec->str == FT_NULL)
	{
		if (temp)
			vec->capacity = vec->capacity / 2;
		vec->str = temp;
		return (FT_ERR);
	}
	idx = -1;
	while (++idx < vec->size && temp)
		vec->str[idx] = temp[idx];
	free(temp);
	return (FT_TRUE);
}

int	ft_expand_outer_vector(t_vector *vec)
{
	t_vector	*temp;
	int			idx;

	idx = -1;
	if (vec->size == vec->capacity)
	{
		temp = vec->inner_vec;
		vec->inner_vec = \
		(t_vector *)malloc(sizeof(t_vector) * (vec->capacity * 2));
		if (vec->inner_vec == FT_NULL)
		{
			vec->inner_vec = temp;
			return (FT_ERR);
		}
		vec->capacity = vec->capacity * 2;
		while (++idx < vec->size)
		{
			vec->inner_vec[idx].fd = temp[idx].fd;
			vec->inner_vec[idx].str = temp[idx].str;
			vec->inner_vec[idx].size = temp[idx].size;
			vec->inner_vec[idx].capacity = temp[idx].capacity;
		}
		free(temp);
	}
	return (FT_TRUE);
}
