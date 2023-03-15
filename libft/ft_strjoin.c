/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:09:43 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/15 08:09:45 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	new_size;
	size_t	s1_idx;
	size_t	s2_idx;

	new_size = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (new_size + 1));
	if (new_str == NULL)
		return (NULL);
	s1_idx = 0;
	while (s1[s1_idx])
	{
		new_str[s1_idx] = s1[s1_idx];
		s1_idx++;
	}
	s2_idx = 0;
	while (s2[s2_idx])
	{
		new_str[s1_idx + s2_idx] = s2[s2_idx];
		s2_idx++;
	}
	new_str[s1_idx + s2_idx] = '\0';
	return (new_str);
}
