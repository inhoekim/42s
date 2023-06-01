/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:49:18 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/01 05:25:52 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include <stdio.h>



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
				return (FT_ERR);
		}
		info.i = -1;
		while (info.splited_str[++(info.i)])
			free(info.splited_str[info.i]);
		free(info.splited_str);
	}
	return (FT_TRUE);
}

void	order_stack(int from, char type)
{
	int partition_size[3];

	if (from == A)
	{
		//order_stack(A)
	}
	if (from == B)
	{

	}
}

static	int *mk_arr(int stack_idx, int size)
{
	t_element	*iter;
	int 		*arr;
	int 		idx;

	arr = (int *)malloc(sizeof(int) * size);
	if (arr == FT_NULL)
		return (FT_NULL);
	iter = get_st(stack_idx)->front;
	idx = 0;
	while (iter != FT_NULL)
	{
		arr[idx++] = iter->num;
		iter = iter->next;
	}
	return (arr);
}

int	main(int argc, char **argv)
{
	if (check_format(argc, argv) == FT_ERR || \
	chk_dup(mrg_sort(mk_arr(A, get_st(A)->size), get_st(A)->size)) == FT_ERR)
	{
		printf("Error\n");
		exit(1);
	}
	order_stack(A, 'L');


	op_rr(A);

	printf("stackA");
	printf("\n===================================\n");
	int *arr = mk_arr(A, get_st(A)->size);
	for (int i = 0; i < get_st(A)->size; i++)
		printf("%d ", arr[i]);
	printf("\n===================================\n");
	printf("stackB");
	printf("\n===================================\n");
	arr = mk_arr(B, get_st(B)->size);
	for (int i = 0; i < get_st(B)->size; i++)
		printf("%d ", arr[i]);
	printf("\n===================================\n");
	return (0);
}
