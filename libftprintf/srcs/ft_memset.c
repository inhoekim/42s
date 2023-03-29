/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:26:47 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/14 05:59:30 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				idx;
	unsigned char	*temp_b;

	idx = 0;
	temp_b = (unsigned char *)b;
	while (len)
	{
		temp_b[idx] = (unsigned char)c;
		idx++;
		len--;
	}
	return ((void *)temp_b);
}
