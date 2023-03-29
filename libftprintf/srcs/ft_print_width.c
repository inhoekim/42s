/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:11:58 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/29 09:11:59 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long long	ft_print_width(int width)
{
	long long	cnt;

	cnt = 0;
	while (width > 0)
	{
		cnt += write(1, " ", 1);
		width--;
	}
	return (cnt);
}
