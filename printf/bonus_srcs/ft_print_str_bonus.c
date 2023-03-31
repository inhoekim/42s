/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:47:42 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/31 10:47:45 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

long long	ft_print_str(t_format *format, char *str)
{
	long long	cnt;
	long long	str_len;

	cnt = 0;
	if (str == FT_NULL)
		str = "(null)";
	str_len = ft_strlen(str);
	if (format->prec && format->prec_width < str_len)
		str_len = format->prec_width;
	if (format->flag_ascii['-'])
	{
		cnt += ft_putstr_fd(str, str_len, 1);
		cnt += ft_print_width(format->width - str_len);
	}
	else
	{
		cnt += ft_print_width(format->width - str_len);
		cnt += ft_putstr_fd(str, str_len, 1);
	}
	return (cnt);
}
