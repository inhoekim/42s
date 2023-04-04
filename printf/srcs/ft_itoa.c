/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:50:27 by inhkim            #+#    #+#             */
/*   Updated: 2023/04/03 19:50:28 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	recur_set_str(char *str, long long num, int depth, int num_len)
{
	if (num / 10 == 0)
	{
		str[num_len - depth] = (num % 10) + '0';
		return ;
	}
	recur_set_str(str, num / 10, depth + 1, num_len);
	str[num_len - depth] = (num % 10) + '0';
}

void	ft_itoa(long long num, char *num_str)
{
	int			num_len;

	if (num_str == FT_NULL)
		return ;
	if (num < 0)
		num *= -1;
	num_len = ft_intlen(num);
	num_str[num_len] = '\0';
	recur_set_str(num_str, num, 0, num_len - 1);
}
