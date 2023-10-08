/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:50:18 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/14 03:37:58 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*casting_s;
	int				idx;

	casting_s = (unsigned char *)s;
	idx = 0;
	while (n)
	{
		casting_s[idx] = '\0';
		idx++;
		n--;
	}
}
