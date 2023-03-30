/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:25:46 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/29 10:25:46 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printft.h"

long long	ft_print_addr(t_format *format, void *p)
{
	long long	cnt;
	long long	str_len;
	char		addr_str[18];

	cnt = 0;
	ft_make_hexstr((size_t)p, addr_str, FT_TRUE, FT_TRUE);
	str_len = ft_strlen(addr_str);
	if (format->flag_ascii['-'])
	{
		cnt += ft_putstr_fd(addr_str, str_len, 1);
		cnt += ft_print_width(format->width - str_len);
	}
	else
	{
		cnt += ft_print_width(format->width - str_len);
		cnt += ft_putstr_fd(addr_str, str_len, 1);
	}
	return (cnt);
}
