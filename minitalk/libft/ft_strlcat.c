/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:43:16 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/14 17:09:00 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;
	int		idx;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	idx = 0;
	if (dst_size > size)
		return (src_size + size);
	while (src[idx] && (size > dst_size + 1 + idx))
	{
		dst[dst_size + idx] = src[idx];
		idx++;
	}			
	dst[dst_size + idx] = 0;
	return (dst_size + src_size);
}
