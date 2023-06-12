/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_util_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:40:01 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/12 15:14:17 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	free_str(t_format_info *info)
{
	info->i = 0;
	while (info->splited_str[info->i])
	{
		free(info->splited_str[info->i]);
		(info->i)++;
	}
	free(info->splited_str);
	return (FT_ERR);
}

int	check_format(int argc, char **argv)
{	
	t_format_info	info;

	info.idx = 0;
	info.splited_str = FT_NULL;
	while (--argc)
	{	
		info.splited_str = ft_split(argv[++(info.idx)]);
		if (info.splited_str == FT_NULL)
			return (FT_ERR);
		info.i = -1;
		while (info.splited_str[++(info.i)])
		{
			info.num = ft_atoi((info.splited_str)[info.i]);
			if ((info.num > FT_INT_MAX) || (info.num < FT_INT_MAX * -1 -1) || \
			push_back(get_st(A), info.num) == FT_ERR)
				return (free_str(&info));
		}
		free_str(&info);
	}
	return (FT_TRUE);
}

int	chk_dup(int *arr)
{
	int	i;

	if (arr == FT_NULL)
		return (FT_ERR);
	i = 0;
	while (i < get_st(A)->size - 1)
	{
		if (arr[i] == arr[i + 1])
		{
			free(arr);
			return (FT_ERR);
		}
		i++;
	}
	return (FT_TRUE);
}
