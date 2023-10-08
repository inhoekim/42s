/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:11:47 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/21 04:41:48 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ret;
	size_t			max;

	max = -1;
	if (size != 0 && count > max / size)
		return (FT_NULL);
	ret = (unsigned char *)malloc(count * size);
	if (ret == 0)
		return (FT_NULL);
	ft_memset(ret, 0, count * size);
	return ((void *)ret);
}
