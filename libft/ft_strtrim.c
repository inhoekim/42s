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

static char	*make_str(char const *s1, size_t left_idx, size_t right_idx)
{
	char	*new_str;
	size_t	new_size;
	size_t	idx;

	if (left_idx >= right_idx)
		new_size = 0;
	else
		new_size = right_idx - left_idx;
	new_str = (char *)malloc(sizeof(char) * (new_size + 1));
	if (new_str == FT_NULL)
		return (FT_NULL);
	idx = 0;
	while (idx < new_size)
		new_str[idx++] = s1[left_idx++];
	new_str[idx] = '\0';
	return (new_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	ascii[256];
	size_t	left_idx;
	size_t	right_idx;

	right_idx = ft_strlen(s1);
	if (right_idx == 0)
		return (ft_strdup(s1));
	ft_memset(ascii, 0, 256);
	left_idx = 0;
	while (set[left_idx] != '\0')
		ascii[(int)set[left_idx++]] += 1;
	left_idx = 0;
	while (s1[left_idx] != '\0')
	{
		if (ascii[(int)s1[left_idx]] == 0)
			break ;
		left_idx++;
	}
	while (right_idx != 0 && s1[right_idx - 1] != '\0')
	{
		if (ascii[(int)s1[right_idx - 1]] == 0)
			break ;
		right_idx--;
	}
	return (make_str(s1, left_idx, right_idx));
}
