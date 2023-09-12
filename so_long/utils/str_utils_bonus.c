/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:53:38 by inhkim            #+#    #+#             */
/*   Updated: 2023/09/13 00:05:16 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "utils.h"

int	ft_strlen(char *str, char end)
{
	long long	cnt;

	cnt = 0;
	if (str == FT_NULL)
		return (-1);
	while (*str != FT_NULL && *str != end)
	{
		if (cnt == INT_MAX)
			return (-1);
		cnt++;
		str++;
	}
	return (cnt);
}

int	chk_str(char *dst, char *src)
{
	int	idx;

	idx = 0;
	while (*src && *src != '\n')
	{
		if (*src != '0' && *src != '1' && *src != 'C' \
		&& *src != 'E' && *src != 'P' && *src != 'H' && *src != 'V')
			return (FT_ERR);
		dst[idx] = *src;
		idx++;
		src++;
	}
	return (FT_TRUE);
}
