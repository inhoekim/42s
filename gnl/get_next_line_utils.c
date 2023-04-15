/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:30:26 by inhkim            #+#    #+#             */
/*   Updated: 2023/04/10 18:30:26 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_clear(t_vec_fd *contents, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
		free(contents[idx].str);
	free(contents);
	return (FT_NULL);
}

long long	ft_strlen(char *str)
{
	long long	idx;

	if (str == FT_NULL)
		return (0);
	idx = 0;
	while (str[idx] != '\0')
		idx++;
	return (idx);
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
}

int	ft_split_newline(t_vector *vec, \
int idx, long long offset, char **ret_str)
{
	char		*str;
	long long	len;

	str = vec->contents[idx].str;
	len = ft_strlen(str);
	*ret_str = (char *)malloc(sizeof(char) * (offset + 1));
	vec->contents[idx].str = (char *)malloc(sizeof(char) * (len - offset + 1));
	if (!(*ret_str) || !vec->contents[idx].str)
	{
		free(str);
		free(*ret_str);
		return (FT_ERR);
	}
	ft_str_copy(*ret_str, str, 0, offset + 1);
	ft_str_copy(vec->contents[idx].str, str, offset + 1, len);
	return (FT_TRUE);
}

int	ft_find_newline(t_vector *vec, \
int idx, long long *offset, char **ret_str)
{
	char	*str;

	str = vec->contents[idx].str;
	while (str[*offset])
	{
		if (str[*offset] == '\n')
		{
			if (ft_split_newline(vec, idx, *offset, ret_str) == FT_ERR)
			{
				ft_clear(vec->contents, vec->size);
				return (FT_ERR);
			}
			return (FT_TRUE);
		}
		*offset = *offset + 1;
	}
	return (FT_FALSE);
}
