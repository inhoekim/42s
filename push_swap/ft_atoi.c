/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:00:39 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/01 04:24:56 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static long	ft_strtol(const char *str, int sign)
{
	long	num;
	long	front;
	long	back;
	int		idx;

	num = 0;
	idx = -1;
	front = (long)FT_LONG_MAX / 10;
	back = (long)FT_LONG_MAX % 10;
	while (str[++idx])
	{
		if ('1' <= str[idx] && str[idx] <= '9')
		{
			if (num > front || (num == front && str[idx] >= back + '0'))
			{
				if (sign == -1 && str[idx] >= '8')
					return (((long)FT_LONG_MAX * -1) - 1);
				return ((long)FT_LONG_MAX);
			}
			num = (num * 10) + (str[idx] - '0');
		}
		else
			return ((long)FT_LONG_MAX) ;
	}
	return (num);
}

long	ft_atoi(const char *str)
{
	long	num;
	int		idx;
	int		sign;

	num = 0;
	idx = 0;
	sign = confirm_sign(&str);
	num = ft_strtol(str, sign);
	return (sign * num);
}