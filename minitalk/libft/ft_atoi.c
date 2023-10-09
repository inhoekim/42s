/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:44:37 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/21 03:48:50 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del_ws(const char **str)
{
	while (**str)
	{
		if ((9 <= **str && **str <= 13) || **str == 32)
			(*str)++;
		else
			break ;
	}
}

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
		if (ft_isdigit(str[idx]))
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
			break ;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	del_ws(&str);
	sign = confirm_sign(&str);
	num = ft_strtol(str, sign);
	return ((int)(sign * num));
}
