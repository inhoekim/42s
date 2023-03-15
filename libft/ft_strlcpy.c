/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:21:04 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/14 16:34:03 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;

	idx = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[idx] && (idx < dstsize - 1))
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = 0;
	return (ft_strlen(src));
}
