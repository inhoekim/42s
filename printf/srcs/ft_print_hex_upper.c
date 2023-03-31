/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:56:04 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/31 01:56:06 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static long long	proc_prec(t_format *fm, \
char *str, long long len, long long actual_len)
{
	long long	cnt;

	cnt = 0;
	if (fm->flag_ascii['-'])
	{
		if (fm->flag_ascii['#'])
			cnt += write(1, "0x", 2);
		cnt += ft_print_zero(fm->prec_width - len);
		cnt += ft_putstr_fd(str, len, 1);
		cnt += ft_print_width(fm->width - actual_len);
	}
	else
	{
		cnt += ft_print_width(fm->width - actual_len);
		if (fm->flag_ascii['#'])
			cnt += write(1, "0x", 2);
		cnt += ft_print_zero(fm->prec_width - len);
		cnt += ft_putstr_fd(str, len, 1);
	}
	return (cnt);
}

static long long	proc_non_prec(t_format *fm, \
char *str, long long len, long long actual_len)
{
	long long	cnt;

	cnt = 0;
	if (fm->flag_ascii['-'])
	{
		if (fm->flag_ascii['#'])
			cnt += write(1, "0x", 2);
		cnt += ft_putstr_fd(str, len, 1);
		cnt += ft_print_width(fm->width - actual_len);
	}
	else
	{
		if (!fm->flag_ascii['0'])
			cnt += ft_print_width(fm->width - actual_len);
		if (fm->flag_ascii['#'])
			cnt += write(1, "0x", 2);
		if (fm->flag_ascii['0'])
			cnt += ft_print_zero(fm->width - actual_len);
		cnt += ft_putstr_fd(str, len, 1);
	}
	return (cnt);
}

long long	ft_print_hex_upper(t_format *format, unsigned int num)
{
	long long	cnt;
	long long	str_len;
	long long	actual_len;
	char		num_str[10];
	int			is_addr;

	is_addr = FT_FALSE;
	cnt = 0;
	if (format->flag_ascii['#'])
		is_addr = FT_TRUE + 1;
	ft_make_hexstr(num, num_str, FT_FALSE, FT_FALSE);
	str_len = ft_strlen(num_str);
	actual_len = str_len + is_addr;
	if (format->prec_width > str_len)
		actual_len = format->prec_width + is_addr;
	if (format->prec)
		cnt += proc_prec(format, num_str, str_len, actual_len);
	else
		cnt += proc_non_prec(format, num_str, str_len, actual_len);
	return (cnt);
}