/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:31:42 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/30 19:31:43 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long long	ft_print_zero(int width)
{
	long long	cnt;

	cnt = 0;
	while (width > 0)
	{
		cnt += write(1, "0", 1);
		width--;
	}
	return (cnt);
}
