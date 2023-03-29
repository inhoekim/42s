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

#include <unistd.h>
#include "../includes/printft.h"

static void	*reverse_str(char *addr_str, size_t right_idx)
{
	size_t	left_idx;
	int		temp_num;

	left_idx = 0;
	while (left_idx < right_idx)
	{
		temp_num = addr_str[left_idx];
		addr_str[left_idx] = addr_str[right_idx];
		addr_str[right_idx] = temp_num;
		left_idx++;
		right_idx--;
	}
}

static char	*make_addr_str(size_t addr)
{
	const char	*hex_set = "0123456789abcdef";
	char		addr_str[18];
	size_t		idx;

	addr_str[0] = '\0';
	idx = 1;
	while (addr)
	{
		addr_str[idx] = hex_set[addr % 16];
		addr /= 16;
		idx++;
	}
	addr_str[idx] = 'x';
	addr_str[++idx] = '0';
	reverse_str(addr_str, idx);
	return (addr_str);
}

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

long long	ft_print_addr(t_format *format, void *p)
{
	long long	cnt;
	long long	str_len;
	char		*addr_str;

	cnt = 0;
	addr_str = make_addr_str((size_t)p);
	str_len = ft_strlen(addr_str);
	if (format->flag_ascii['-'])
	{
		cnt += put_str(addr_str, str_len);
		cnt += ft_print_width(format->width - str_len);
	}
	else
	{
		cnt += ft_print_width(format->width - str_len);
		cnt += put_str(addr_str, str_len);
	}
	return (cnt);
}
