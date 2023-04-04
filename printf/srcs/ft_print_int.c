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

static void	init_wdata(t_check_wdata *wdata)
{
	wdata->cnt = 0;
	wdata->is_minus = 0;
}

static void	pre_proc(t_format *fm, int is_minus, t_len_data *len_data)
{
	len_data->actual_len = len_data->str_len;
	if (!fm->prec)
	{
		if (is_minus)
			len_data->actual_len += 1;
		if (is_minus && fm->flag_ascii['0'])
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
		if (is_minus)
			len_data->actual_len += 1;
	}
}

static t_check_wdata	proc_print_int_flag(t_format fm, \
char *str, t_len_data *len_data, int is_minus)
{
	t_check_wdata	wdata;

	init_wdata(&wdata);
	if (fm.flag_ascii['-'])
	{
		if (is_minus)
			ft_err(write(1, "-", 1), &wdata);
		if (!is_minus && fm.flag_ascii['+'])
			ft_err(write(1, "+", 1), &wdata);
		ft_err(ft_print_zero(fm.prec_width - len_data->str_len), &wdata);
		ft_err(ft_putstr_fd(str, len_data->str_len, 1), &wdata);
		ft_err(ft_print_width(fm.width - len_data->actual_len), &wdata);
	}
	else
	{
		ft_err(ft_print_width(fm.width - len_data->actual_len), &wdata);
		if (is_minus)
			ft_err(write(1, "-", 1), &wdata);
		if (!is_minus && fm.flag_ascii['+'])
			ft_err(write(1, "+", 1) , &wdata);
		ft_err(ft_print_zero(fm.prec_width - len_data->str_len), &wdata);
		ft_err(ft_putstr_fd(str, len_data->str_len, 1), &wdata);
	}
	return (wdata);
}

long long	ft_print_int(t_format format, int num)
{
	t_check_wdata	wdata;
	t_len_data		len_data;
	char			num_str[12];
	int				temp;

	temp = 0;
	ft_itoa(num, num_str);
	if (num == 0 && format.prec)
		num_str[0] = '\0';
	len_data.str_len = ft_strlen(num_str);
	if ((format.flag_ascii[' '] || format.flag_ascii['+']) && num >= 0)
	{
		if (format.flag_ascii[' '])
			temp = write(1, " ", 1);
		(format.width)--;
	}
	pre_proc(&format, num < 0, &len_data);
	wdata = proc_print_int_flag(format, num_str, &len_data, num < 0);
	if (wdata.is_minus || temp < 0)
		return (-1);
	return (wdata.cnt + temp);
}

long long	ft_print_uint(t_format format, unsigned int num)
{
	t_check_wdata	wdata;
	t_len_data		len_data;
	char			num_str[12];

	ft_itoa(num, num_str);
	if (num == 0 && format.prec)
		num_str[0] = '\0';
	len_data.str_len = ft_strlen(num_str);
	pre_proc(&format, num < 0, &len_data);
	wdata = proc_print_int_flag(format, num_str, &len_data, num < 0);
	if (wdata.is_minus)
		return (-1);
	return (wdata.cnt);
}
