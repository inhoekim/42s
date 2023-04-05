/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:30:38 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/30 19:30:41 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	print_detail(t_format fm, \
t_len_data *len_data, char *str, long long *cnt)
{
	if (ft_err(ft_print_width(fm.width - len_data->actual_len), cnt))
		return (1);
	if (len_data->is_minus)
		if (ft_err(write(1, "-", 1), cnt))
			return (1);
	if (!(len_data->is_minus) && fm.flag_ascii['+'])
		if (ft_err(write(1, "+", 1), cnt))
			return (1);
	if (ft_err(ft_print_zero(fm.prec_width - len_data->str_len), cnt) || \
	ft_err(ft_putstr_fd(str, len_data->str_len, 1), cnt))
		return (1);
	return (0);
}

static void	pre_proc(t_format *fm, t_len_data *len_data)
{
	len_data->actual_len = len_data->str_len;
	if (!fm->prec)
	{
		if (len_data->is_minus)
			len_data->actual_len += 1;
		if (len_data->is_minus && fm->flag_ascii['0'])
			len_data->str_len += 1;
		if (fm->flag_ascii['0'])
		{
			fm->prec_width = fm->width;
			len_data->actual_len = fm->width;
		}
	}
	else
	{
		if (fm->prec_width > len_data->actual_len)
			len_data->actual_len = fm->prec_width;
		if (len_data->is_minus)
			len_data->actual_len += 1;
	}
}

static long long	proc_print_int_flag(t_format fm, \
char *str, t_len_data *len_data)
{
	long long	cnt;

	cnt = 0;
	if (fm.flag_ascii['-'])
	{
		if (len_data->is_minus)
			if (ft_err(write(1, "-", 1), &cnt))
				return (-1);
		if (!(len_data->is_minus) && fm.flag_ascii['+'])
			if (ft_err(write(1, "+", 1), &cnt))
				return (-1);
		if (ft_err(ft_print_zero(fm.prec_width - len_data->str_len), &cnt) || \
		ft_err(ft_putstr_fd(str, len_data->str_len, 1), &cnt) || \
		ft_err(ft_print_width(fm.width - len_data->actual_len), &cnt))
			return (-1);
	}
	else
		if (print_detail(fm, len_data, str, &cnt))
			return (-1);
	return (cnt);
}

long long	ft_print_int(t_format format, int num)
{
	long long		cnt;
	t_len_data		len_data;
	char			num_str[12];

	cnt = 0;
	ft_itoa(num, num_str);
	if (num == 0 && format.prec)
		num_str[0] = '\0';
	len_data.str_len = ft_strlen(num_str);
	if ((format.flag_ascii[' '] || format.flag_ascii['+']) && num >= 0)
	{
		if (format.flag_ascii[' '])
			cnt = write(1, " ", 1);
		(format.width)--;
	}
	if (cnt < 0)
		return (-1);
	len_data.is_minus = 0;
	if (num < 0)
		len_data.is_minus = 1;
	pre_proc(&format, &len_data);
	cnt += proc_print_int_flag(format, num_str, &len_data);
	return (cnt);
}

long long	ft_print_uint(t_format format, unsigned int num)
{
	long long		cnt;
	t_len_data		len_data;
	char			num_str[12];

	ft_itoa(num, num_str);
	if (num == 0 && format.prec)
		num_str[0] = '\0';
	len_data.str_len = ft_strlen(num_str);
	len_data.is_minus = 0;
	pre_proc(&format, &len_data);
	cnt = proc_print_int_flag(format, num_str, &len_data);
	return (cnt);
}
