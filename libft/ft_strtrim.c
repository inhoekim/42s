/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:35:34 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/15 08:35:36 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
}

static size_t	get_left_idx(char const *s1, char const *set)
{
	size_t	left_idx;
	size_t	set_idx;
	size_t	set_len;

	left_idx = 0;
	set_len = ft_strlen(set);
	while (s1[left_idx])
	{
		set_idx = 0;
		while (set_idx < set_len)
		{
			if (s1[left_idx] == set[set_idx])
			{
				left_idx++;
				break;
			}
			else
				set_idx++;
		}
		if (set_idx == set_len)
			return (left_idx);
	}
	return (left_idx);
}

static size_t	get_right_idx(char const *s1, char const *set)
{
	long long	right_idx;
	long long	set_idx;
	long long	set_len;

	right_idx = (long long)ft_strlen(s1) - 1;
	set_len = (long long)ft_strlen(set);
	while (right_idx > 0 && s1[right_idx])
	{
		set_idx = 0;
		while (set_idx < set_len)
		{
			if (s1[right_idx] == set[set_idx])
			{
				right_idx--;
				break;
			}
			else
				set_idx++;
		}
		if (set_idx == set_len)
			return ((size_t)right_idx);
	}
	return ((size_t)right_idx);
}

static void	set_new_str(char *new_str, char const *s1, \
long long left_idx, long long right_idx)
{
	long long	idx;

	idx = 0;
	while (left_idx + idx < right_idx + 1)
	{
		new_str[idx] = s1[left_idx + idx];
		idx++;
	}
	new_str[idx] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left_idx;
	size_t	right_idx;
	size_t	str_size;
	char	*new_str;
	
	if (set == NULL || ft_strlen(set) == 0)
		return ((char *)s1);
	left_idx = get_left_idx(s1, set);
	right_idx = get_right_idx(s1, set);
	if (left_idx > right_idx)
		str_size = 0;
	else if (left_idx == right_idx)
		str_size = 1;
	else
		str_size = right_idx - left_idx;
	new_str = (char *)malloc(sizeof(char) * (str_size + 1));
	if (new_str == NULL)
		return (NULL);
	set_new_str(new_str, s1, left_idx, right_idx);
	return (new_str);
}
