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

#include "../includes/printft.h"
#include <unistd.h>

static int	get_int_len(long long n)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

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

static void	int_to_alpha(long long num, char *num_str)
{
	int			is_minus;
	int			num_len;

	is_minus = FT_FALSE;
	if (num < 0)
	{
		num *= -1;
		is_minus = FT_TRUE;
	}
	num_len = get_int_len(num);
	if (is_minus)
		num_str[0] = '-';
	num_str[num_len + is_minus] = '\0';
	recur_set_str(num_str, num, 0, num_len + is_minus - 1);
}

static long long	proc_print_int_flag(t_format *fm, \
char *str, long long len, long long actual_len)
{
	long long	cnt;

	cnt = 0;
	if (fm->flag_ascii['-'])
	{
		cnt += ft_print_zero(fm->prec_width - len);
		cnt += ft_putstr_fd(str, len, 1);
		cnt += ft_print_width(fm->width - actual_len);
	}
	else
	{
		cnt += ft_print_width(fm->width - actual_len);
		cnt += ft_print_zero(fm->prec_width - len);
		cnt += ft_putstr_fd(str, len, 1);
	}
	return (cnt);
}

long long	ft_print_int(t_format *format, long long num)
{
	long long	cnt;
	long long	str_len;
	long long	actual_len;
	char		num_str[11];

	if (num < -FT_INT_MAX - 1 || num > FT_INT_MAX)
		return (0);
	cnt = 0;
	int_to_alpha(num, num_str);
	str_len = ft_strlen(num_str);
	if (format->flag_ascii[' '])
	{
		cnt += write(1, " ", 1);
		(format->width)--;
	}
	else if (format->flag_ascii['+'])
	{
		cnt += write(1, "+", 1);
		(format->width)--;
	}
	actual_len = str_len;
	if (format->prec_width > str_len)
		actual_len = format->prec_width;
	cnt += proc_print_int_flag(format, num_str, str_len, actual_len);
	return (cnt);
}
