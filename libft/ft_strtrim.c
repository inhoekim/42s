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

size_t	get_left_idx(char const *s1, char const *set)
{
	size_t	left_idx;
	size_t	set_len;
	size_t	cnt;

	left_idx = 0;
	set_len = ft_strlen(set);
	cnt = 0;
	while (cnt < set_len)
	{
		if (s1[left_idx] && s1[left_idx] == set[cnt])
		{
			left_idx++;
			set_idx++;
		}
		set_idx++;
	}
	return (left_idx);
}

long long	get_right_idx(char const *s1, char const *set)
{
	long long	right_idx;
	long long	set_idx;

	right_idx = (long long)ft_strlen(s1);
	set_idx = 0;
	while (set[set_idx] && right_idx > 0)
	{
		if (s1[right_idx - 1] && s1[right_idx] == set[set_idx])
		{
			right_idx--;
			set_idx = -1;
		}
		set_idx++;
	}
	return (right_idx);
}

void	set_str(char const *s1, char *new_str, \
long long left_idx, long long right_idx)
{
	long long	idx;

	idx = 0;
	while (left_idx + idx < right_idx)
	{
		new_str[idx] = s1[left_idx + idx];
		idx++;
	}
	new_str[idx] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	long long	left_idx;
	long long	right_idx;
	char		*new_str;
	long long	str_size;

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
	set_str(s1, new_str, left_idx, right_idx);
	return (new_str);
}
