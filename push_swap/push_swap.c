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

int	push_back(t_deque *stack, int val)
{
	t_element	*element;

	element = (t_element *)malloc(sizeof(t_element));
	if (element == FT_NULL)
		return (FT_ERR);
	if (stack->front == FT_NULL)
		stack->front = element;
	element->num = val;
	element->before = stack->tail;
	element->next = FT_NULL;
	if (stack->tail != FT_NULL)
		stack->tail->next = element;
	stack->tail = element;
	stack->size++;
	return (FT_TRUE);
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

static	int *make_arr(int stack_idx, int size)
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
	check_dup(merge_sort(make_arr(A, get_st(A)->size), get_st(A)->size)) == FT_ERR)
	{
		printf("Error\n");
		exit(1);
	}
	order_stack(A, 'L');

	int *arr = make_arr(A, get_st(A)->size);
	for (int i = 0; i < get_st(A)->size; i++)
		printf("%d ", arr[i]);
	printf("\n===================================\n");
	arr = merge_sort(arr, get_st(A)->size);
	for (int i = 0; i < get_st(A)->size; i++)
		printf("%d ", arr[i]);
	printf("\n===================================\n");
	return (0);
}
