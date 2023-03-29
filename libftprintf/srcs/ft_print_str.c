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
#include <unistd.h>

static long long	put_str(char *str, long long len)
{
	long long	cnt;
	int			idx;

	cnt = 0;
	idx = 0;
	while (str[idx] && len > idx)
	{
		cnt += write(1, &str[idx], 1);
		idx++;
	}
	return (cnt);
}

long long	ft_print_str(t_format *format, char *str)
{
	long long	cnt;
	long long	str_len;

	cnt = 0;
	if (str == FT_NULL)
		str = "(null)";
	str_len = ft_strlen(str);
	if (format->prec)
		str_len = format->prec_width;
	if (format->flag_ascii['-'])
	{
		cnt += put_str(str, str_len);
		cnt += ft_print_width(format->width - str_len);
	}
	else
	{
		cnt += ft_print_width(format->width - str_len);
		cnt += put_str(str, str_len);
	}
	return (cnt);
}