/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 04:24:34 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/14 04:24:35 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		idx;

	idx = 0;
	if (len == 0 || (dst == 0 && src == 0))
		return ((void *)dst);
	if ((char *)dst > (char *)src)
	{
		idx = 1;
		while (idx <= len)
		{
			((char *)dst)[len - idx] = ((char *)src)[len - idx];
			idx++;
		}
	}
	else
	{
		while (idx < len)
		{
			((char *)dst)[idx] = ((char *)src)[idx];
			idx++;
		}
	}
	return ((void *)dst);
}
