/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:46:54 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/31 10:46:57 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

long long	ft_print_addr(t_format format, long long p)
{
	long long	cnt;
	long long	str_len;
	char		addr_str[19];

	cnt = 0;
	ft_make_hexstr((long long)p, addr_str, FT_TRUE + 1, FT_TRUE);
	str_len = ft_strlen(addr_str);
	if (format.flag_ascii['-'])
	{
		cnt += ft_putstr_fd(addr_str, str_len, 1);
		cnt += ft_print_width(format.width - str_len);
	}
	else
	{
		cnt += ft_print_width(format.width - str_len);
		cnt += ft_putstr_fd(addr_str, str_len, 1);
	}
	return (cnt);
}
