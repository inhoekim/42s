/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:47:03 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/31 10:47:06 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ft_printf_bonus.h>

long long	ft_print_percent(t_format format)
{
	long long	cnt;

	cnt = 0;
	if (format.flag_ascii['-'])
	{
		cnt += write(1, "%", 1);
		cnt += ft_print_width(format.width - 1);
	}
	else
	{
		cnt += ft_print_width(format.width - 1);
		cnt += write(1, "%", 1);
	}	
	return (cnt);
}
