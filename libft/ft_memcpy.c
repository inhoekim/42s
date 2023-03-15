/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:04:09 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/14 04:23:59 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int	idx;

	idx = 0;
	while (n)
	{
		if (dst == 0 && src == 0)
			break ;
		((unsigned char *)dst)[idx] = ((unsigned char *)src)[idx];
		idx++;
		n--;
	}
	return (dst);
}
