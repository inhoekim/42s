/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:48:25 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/31 10:48:27 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long long	ft_print_width(int width)
{
	long long	cnt;
	long long	temp;

	cnt = 0;
	while (width > 0)
	{
		temp = write(1, " ", 1);
		if (temp < 0)
			return (-1);
		cnt += temp;
		width--;
	}
	return (cnt);
}
