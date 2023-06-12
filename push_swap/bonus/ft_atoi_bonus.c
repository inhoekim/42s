/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:00:39 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/12 14:42:03 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	confirm_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '+')
		(*str)++;
	else if (**str == '-')
	{
		(*str)++;
		sign = -1;
	}
	return (sign);
}

static long long	ft_strtol(const char *str, int sign)
{
	long long	num;
	long long	f;
	long long	b;
	int			idx;

	num = 0;
	idx = -1;
	f = (long long)FT_LONG_MAX / 10;
	b = (long long)FT_LONG_MAX % 10;
	while (str[++idx])
	{
		if ('0' <= str[idx] && str[idx] <= '9')
		{
			if (num > f || (num == f && str[idx] >= b + '0'))
			{
				if (sign < 0 && (num > f || (num == f && str[idx] >= '8')))
					return (((long long)FT_LONG_MAX * -1) - 1);
				return ((long long)FT_LONG_MAX);
			}
			num = (num * 10) + (str[idx] - '0');
		}
		else
			return ((long long)FT_LONG_MAX);
	}
	return (num);
}

long long	ft_atoi(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = confirm_sign(&str);
	if (*str == FT_NULL)
		return ((long long)FT_LONG_MAX);
	num = ft_strtol(str, sign);
	if (num == FT_LONG_MAX * -1 - 1)
		return (num);
	return (sign * num);
}
