/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:45:40 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/31 10:45:45 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
