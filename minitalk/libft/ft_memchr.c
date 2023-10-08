/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 06:49:51 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/14 06:49:54 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			idx;
	unsigned char	*temp_s;

	idx = 0;
	temp_s = (unsigned char *)s;
	while (idx < n)
	{
		if (temp_s[idx] == (unsigned char)c)
			return ((void *)(temp_s + idx));
		idx++;
	}
	return (0);
}
