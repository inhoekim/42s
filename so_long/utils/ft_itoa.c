/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:45:16 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/28 15:45:17 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../so_long.h"

static void	recur_set_str(char *str, unsigned int num, \
unsigned int depth, unsigned int num_len)
{
	if (num / 10 == 0)
	{
		str[num_len - depth] = (num % 10) + '0';
		return ;
	}
	recur_set_str(str, num / 10, depth + 1, num_len);
	str[num_len - depth] = (num % 10) + '0';
}

unsigned int	num_len(unsigned int n)
{
	unsigned int	len;

	len = 1;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(unsigned int n)
{
	char			*num_alpha;
	unsigned int	len;

	len = num_len(n);
	num_alpha = (char *)malloc(sizeof(char) * (len + 2));
	if (num_alpha == FT_NULL)
		return (FT_NULL);
	num_alpha[len] = '\n';
	num_alpha[len + 1] = '\0';
	recur_set_str(num_alpha, n, 0, len - 1);
	return (num_alpha);
}
