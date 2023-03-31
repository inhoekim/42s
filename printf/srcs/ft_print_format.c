/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 05:36:27 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/29 05:36:27 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_print_format(t_format *format, va_list *args)
{
	long long	print_cnt;

	print_cnt = 0;
	if (format->conversion == 'c')
		print_cnt += ft_print_char(format, (char)va_arg(*args, int));
	if (format->conversion == 's')
		print_cnt += ft_print_str(format, (char *)va_arg(*args, char *));
	if (format->conversion == 'p')
		print_cnt += ft_print_addr(format, (long long)va_arg(*args, void *));
	if (format->conversion == 'd' || format->conversion == 'i')
		print_cnt += ft_print_int(format, (long long)va_arg(*args, long long));
	if (format->conversion == 'x')
		print_cnt += ft_print_hex_lower(format, \
		(unsigned int)va_arg(*args, unsigned int));
	if (format->conversion == 'X')
		print_cnt += ft_print_hex_lower(format, \
		(unsigned int)va_arg(*args, unsigned int));
	if (format->conversion == '%')
		print_cnt += ft_print_percent(format);
	return (print_cnt);
}
