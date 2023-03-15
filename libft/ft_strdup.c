/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:39:56 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/14 19:39:57 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*new_str;
	int		idx;

	size = ft_strlen(s1);
	new_str = (char *)malloc(sizeof(char) * (size + 1));
	if (new_str == 0)
		return (0);
	idx = 0;
	while (s1[idx])
	{
		new_str[idx] = s1[idx];
		idx++;
	}
	new_str[idx] = 0;
	return (new_str);
}
