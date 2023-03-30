/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:56:51 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/30 20:56:53 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printft.h"
#include <unistd.h>

static long long	proc_print_int_flag(t_format *fm, \
char *str, long long len, long long actual_len)
{
	long long	cnt;

	cnt = 0;
	if (fm->flag_ascii['-'])
	{
		cnt += ft_print_zero(fm->prec_width - len);
		cnt += ft_putstr_fd(str, len, 1);
		cnt += ft_print_width(fm->width - actual_len);
	}
	else
	{
		cnt += ft_print_width(fm->width - actual_len);
		cnt += ft_print_zero(fm->prec_width - len);
		cnt += ft_putstr_fd(str, len, 1);
	}
	return (cnt);
}

long long	ft_print_hex_lower(t_format *format, unsigned int num)
{
	long long	cnt;
	long long	str_len;
	long long	actual_len;
	char 		num_str[10];
	int 		is_addr;

	is_addr = FT_FALSE;
	cnt = 0;
	if (format->flag_ascii['#'])
		is_addr = FT_TRUE;
	ft_make_hexstr(num, num_str, is_addr);
	str_len = ft_strlen(num_str);
	actual_len = str_len;
	if (format->prec_width > str_len)
		actual_len = format->prec_width;
	cnt += proc_print_int_flag(format, num_str, str_len, actual_len);
	return (cnt);
}
