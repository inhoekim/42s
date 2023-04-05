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

#include "ft_printf.h"

long long	ft_print_addr(t_format format, long long p)
{
	long long	str_len;
	char		addr_str[19];

	ft_make_hexstr((long long)p, addr_str, FT_TRUE + 1, FT_TRUE);
	str_len = ft_strlen(addr_str);
	if (format.flag_ascii['-'])
	{
		if (ft_putstr_fd(addr_str, str_len, 1) == -1 || \
		ft_print_width(format.width - str_len) == -1)
			return (-1);
	}
	else
	{
		if (ft_print_width(format.width - str_len) == -1 || \
		ft_putstr_fd(addr_str, str_len, 1) == -1)
			return (-1);
	}
	if (format.width > str_len)
		return (format.width);
	return (str_len);
}
