/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:23:07 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/18 18:23:09 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_itoa(int n)
{
	long long	num;
	char		*num_alpha;
	int			is_minus;
	int			num_len;

	is_minus = FT_FALSE;
	num = (long long)n;
	if (num < 0)
	{
		num *= -1;
		is_minus = FT_TRUE;
	}
	num_len = get_int_len(num);
	num_alpha = (char *)malloc(sizeof(char) * (num_len + is_minus + 1));
	if (num_alpha == FT_NULL)
		return (FT_NULL);
	if (is_minus)
		num_alpha[0] = '-';
	num_alpha[num_len + is_minus] = '\0';
	recur_set_str(num_alpha, num, 0, num_len + is_minus - 1);
	return (num_alpha);
}
