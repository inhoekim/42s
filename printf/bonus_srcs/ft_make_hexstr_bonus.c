/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_hexstr_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:49:09 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/31 10:49:13 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	reverse_str(char *addr_str, size_t right_idx)
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

void	ft_make_hexstr(size_t addr, char *addr_str, \
int is_addr, int lower_case)
{
	const char	*lower_hex = "0123456789abcdef";
	const char	*upper_hex = "0123456789ABCDEF";
	size_t		idx;

	addr_str[0] = '\0';
	if (addr == 0)
		addr_str[1] = '0';
	idx = 1;
	while (addr)
	{
		if (lower_case)
			addr_str[idx] = lower_hex[addr % 16];
		else
			addr_str[idx] = upper_hex[addr % 16];
		addr /= 16;
		idx++;
	}
	if (is_addr)
	{
		addr_str[idx] = 'x';
		addr_str[++idx] = '0';
	}
	reverse_str(addr_str, idx);
}
