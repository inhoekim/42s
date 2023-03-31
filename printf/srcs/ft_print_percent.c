/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 02:18:49 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/31 02:18:50 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

long long	ft_print_percent(t_format *format)
{
	long long	cnt;

	cnt = 0;
	if (format->flag_ascii['-'])
	{
		cnt += write(1, "%", 1);
		cnt += ft_print_width(format->width - 1);
	}
	else
	{
		cnt += ft_print_width(format->width - 1);
		cnt += write(1, "%", 1);
	}	
	return (cnt);
}
