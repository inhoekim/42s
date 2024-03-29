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

#include "ft_printf.h"
#include <unistd.h>

static long long	print_addr_prefix(char **str)
{
	long long	cnt;

	cnt = ft_putstr_fd(*str, 2, 1);
	*str = *str + 2;
	return (cnt);
}

static int	print_detail(t_format fm, \
char *str, long long actual_len, long long *cnt)
{
	if (!fm.flag_ascii['0'])
		if (ft_err(ft_print_width(fm.width - actual_len), cnt))
			return (1);
	if (fm.flag_ascii['#'] && actual_len >= 3)
		if (ft_err(print_addr_prefix(&str), cnt))
			return (1);
	if (fm.flag_ascii['0'])
		if (ft_err(ft_print_zero(fm.width - actual_len), cnt))
			return (1);
	if (ft_err(ft_putstr_fd(str, ft_strlen(str), 1), cnt))
		return (1);
	return (0);
}

static long long	proc_prec(t_format fm, \
char *str, long long len, long long actual_len)
{
	long long	cnt;

	cnt = 0;
	if (fm.flag_ascii['-'])
	{
		if (fm.flag_ascii['#'] && actual_len >= 3 && len != 0)
			if (ft_err(print_addr_prefix(&str), &cnt))
				return (-1);
		if (ft_err(ft_print_zero(fm.prec_width - len), &cnt) || \
		ft_err(ft_putstr_fd(str, ft_strlen(str), 1), &cnt) || \
		ft_err(ft_print_width(fm.width - actual_len), &cnt))
			return (-1);
	}
	else
	{
		if (ft_err(ft_print_width(fm.width - actual_len), &cnt))
			return (-1);
		if (fm.flag_ascii['#'] && actual_len >= 3 && len != 0)
			if (ft_err(print_addr_prefix(&str), &cnt))
				return (-1);
		if (ft_err(ft_print_zero(fm.prec_width - len), &cnt) || \
		ft_err(ft_putstr_fd(str, ft_strlen(str), 1), &cnt))
			return (-1);
	}
	return (cnt);
}

static long long	proc_non_prec(t_format fm, \
char *str, long long actual_len)
{
	long long	cnt;

	cnt = 0;
	if (fm.flag_ascii['-'])
	{
		if (fm.flag_ascii['#'] && actual_len >= 3)
			if (ft_err(print_addr_prefix(&str), &cnt))
				return (-1);
		if (ft_err(ft_putstr_fd(str, ft_strlen(str), 1), &cnt) || \
		ft_err(ft_print_width(fm.width - actual_len), &cnt))
			return (-1);
	}
	else
		if (print_detail(fm, str, actual_len, &cnt))
			return (-1);
	return (cnt);
}

long long	ft_print_hex(t_format format, unsigned int num, int lower_case)
{
	long long		cnt;
	long long		str_len;
	long long		actual_len;
	char			num_str[11];
	int				is_addr;

	is_addr = FT_FALSE;
	if (format.flag_ascii['#'] && num != 0)
		is_addr = FT_TRUE + 1;
	ft_make_hexstr(num, num_str, is_addr, lower_case);
	if (num == 0 && format.prec)
		num_str[0] = '\0';
	str_len = ft_strlen(num_str) - is_addr;
	actual_len = str_len + is_addr;
	if (format.prec_width > str_len)
		actual_len = format.prec_width + is_addr;
	if (format.prec)
		cnt = proc_prec(format, num_str, str_len, actual_len);
	else
		cnt = proc_non_prec(format, num_str, actual_len);
	return (cnt);
}
