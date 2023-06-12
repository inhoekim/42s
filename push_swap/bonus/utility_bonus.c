/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 01:57:52 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/12 19:49:55 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_deque	*get_st(int type)
{
	static t_deque	stacks[2];

	if (type == A)
		return (&stacks[A]);
	if (type == B)
		return (&stacks[B]);
	return (FT_NULL);
}

int	**mk_arr(int **arr, int size)
{
	t_element	*iter;
	int			idx;

	*arr = (int *)malloc(sizeof(int) * size);
	if (*arr == FT_NULL)
		return (FT_NULL);
	iter = get_st(A)->front;
	idx = 0;
	while (idx < size)
	{
		(*arr)[idx++] = iter->num;
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

void	clear_stack(void)
{
	t_element	*iter;

	iter = get_st(A)->front;
	while (iter != FT_NULL)
	{
		get_st(A)->front = iter->next;
		free(iter);
		iter = get_st(A)->front;
	}
}

int	sorted_check(int *arr)
{
	t_element	*iter;
	int			idx;

	idx = -1;
	iter = get_st(A)->front;
	while (++idx < get_st(A)->size)
	{
		if (arr[idx] != iter->num)
			return (FT_ERR);
		iter = iter->next;
	}
	return (FT_TRUE);
}
