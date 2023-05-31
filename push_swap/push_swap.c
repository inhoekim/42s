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
	return (FT_TRUE);
}

int	check_format(t_deque (*stacks)[2], int argc, char **argv)
{	
	t_format_info	info;

	info.idx = 0;
	info.cnt = 0;
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
			push_back(stacks[A], info.num) == FT_ERR)
				return (FT_ERR);
		}
		info.i = -1;
		while (info.splited_str[++(info.i)])
			free(info.splited_str[info.i]);
		free(info.splited_str);
	}
	return (FT_TRUE);
}

int	main(int argc, char **argv)
{
	t_deque	stacks[2];
	//int		*arr;
	int		size;

	stacks[A].front = FT_NULL;
	stacks[A].tail = FT_NULL;
	stacks[B].front = FT_NULL;
	stacks[B].tail = FT_NULL;
	size = check_format(&stacks, argc, argv);
	if (size == FT_ERR)
	{
		printf("Error\n");
		exit(1);
	}
	/*
	make_arr(arr);
	if (size == FT_ERR || sort_arr(arr))
	{
		printf("Error\n");
		exit(1);
	}
	*/
	t_element	*iter = stacks[A].front;
	while(iter != FT_NULL) {
		printf("%d ", iter->num);
		iter = iter->next;
	}
	printf("\n");
	return (0);
}
