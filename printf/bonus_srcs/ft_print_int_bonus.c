/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:45:58 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/31 10:46:02 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

static void	pre_proc(t_format *fm, int is_minus, \
long long *actual_len, long long *str_len)
{
	*actual_len = *str_len;
	if (!fm->prec)
	{
		if (is_minus)
			*actual_len += 1;
		if (is_minus && fm->flag_ascii['0'])
			*str_len += 1;
		if (fm->flag_ascii['0'])
		{
			fm->prec_width = fm->width;
			*actual_len = fm->width;
		}
	}
	else
	{
		if (fm->prec_width > *actual_len)
			*actual_len = fm->prec_width;
		if (is_minus)
			*actual_len += 1;
	}
}

static long long	proc_print_int_flag(t_format *fm, \
char *str, long long len, long long actual_len, int is_minus)
{
	long long	cnt;

	cnt = 0;
	if (fm->flag_ascii['-'])
	{
		if (is_minus)
			cnt += write(1, "-", 1);
		cnt += ft_print_zero(fm->prec_width - len);
		cnt += ft_putstr_fd(str, len, 1);
		cnt += ft_print_width(fm->width - actual_len);
	}
	else
	{
		cnt += ft_print_width(fm->width - actual_len);
		if (is_minus)
			cnt += write(1, "-", 1);
		cnt += ft_print_zero(fm->prec_width - len);
		cnt += ft_putstr_fd(str, len, 1);
	}
	return (cnt);
}

long long	ft_print_int(t_format *format, int num)
{
	long long	cnt;
	long long	str_len;
	long long	actual_len;
	char		num_str[12];

	cnt = 0;
	ft_uitoa(num, num_str);
	str_len = ft_strlen(num_str);
	if (format->flag_ascii[' '])
	{
		cnt += write(1, " ", 1);
		(format->width)--;
	}
	else if (format->flag_ascii['+'])
	{
		cnt += write(1, "+", 1);
		(format->width)--;
	}
	pre_proc(format, num < 0, &actual_len, &str_len);
	cnt += proc_print_int_flag(format, num_str, str_len, actual_len, num < 0);
	return (cnt);
}

long long	ft_print_uint(t_format *format, unsigned int num)
{
	long long	cnt;
	long long	str_len;
	long long	actual_len;
	char		num_str[12];

	cnt = 0;
	ft_uitoa(num, num_str);
	str_len = ft_strlen(num_str);
	pre_proc(format, 0, &actual_len, &str_len);
	cnt += proc_print_int_flag(format, num_str, str_len, actual_len, 0);
	return (cnt);
}
