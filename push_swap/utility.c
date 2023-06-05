/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 01:57:52 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/05 23:41:29 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*get_st(int type)
{
	static t_deque	stacks[2];

	if (type == A)
		return (&stacks[A]);
	if (type == B)
		return (&stacks[B]);
	return (FT_NULL);
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
	free(arr);
	return (FT_TRUE);
}

int	*mk_arr(int stack_idx, int size)
{
	t_element	*iter;
	int			*arr;
	int			idx;

	arr = (int *)malloc(sizeof(int) * size);
	if (arr == FT_NULL)
		return (FT_NULL);
	iter = get_st(stack_idx)->front;
	idx = 0;
	while (idx < size)
	{
		arr[idx++] = iter->num;
		iter = iter->next;
	}
	return (arr);
}

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
