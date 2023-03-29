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

#include <stdarg.h>
#include "./includes/printft.h"

long long	ft_print_format(t_format format, va_list *args)
{
	long long	print_cnt;

	print_cnt = 0;
	if (format.conversion == 'c')
		print_cnt += ft_print_char(format, (char)va_arg(*args, int));
	if (format.conversion == 's')
		print_cnt += ft_print_str(format, (char *)va_arg(*args, char *));
	if (format.conversion == 'p')
		print_cnt += ft_print_addr(format, (void *)va_arg(*args, void *));
	return (print_cnt);
}
