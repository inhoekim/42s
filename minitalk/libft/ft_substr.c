/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 06:53:48 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/15 06:53:49 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*new_str;
	size_t		src_size;
	size_t		new_size;
	size_t		idx;

	src_size = ft_strlen(s);
	if (src_size < start)
		new_size = 0;
	else
		new_size = src_size - start;
	if (len < new_size)
		new_size = len;
	new_str = (char *)malloc(sizeof(char) * (new_size + 1));
	if (new_str == FT_NULL)
		return (FT_NULL);
	idx = 0;
	while (idx < new_size)
	{
		new_str[idx] = s[start];
		idx++;
		start++;
	}
	new_str[idx] = '\0';
	return (new_str);
}
