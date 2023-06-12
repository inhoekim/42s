/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 01:57:52 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/12 11:28:32 by inhkim           ###   ########.fr       */
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

int	push_back(t_deque *stack, int val)
{
	t_element	*element;

	element = (t_element *)malloc(sizeof(t_element));
	if (element == FT_NULL)
		return (FT_ERR);
	element->before = FT_NULL;
	element->next = FT_NULL;
	element->num = val;
	if (stack->size == 0)
		stack->front = element;
	else
	{
		element->before = stack->tail;
		stack->tail->next = element;
	}
	stack->tail = element;
	stack->size++;
	return (FT_TRUE);
}
