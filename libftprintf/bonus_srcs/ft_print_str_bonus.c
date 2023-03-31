/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:18:13 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/29 09:18:13 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printft.h"

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
