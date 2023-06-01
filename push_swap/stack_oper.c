/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:58:43 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/01 01:08:49 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	op_r(int stack_idx)
{
	const char	label[3] = {'a', 'b', 'r'};
	int			idx;
	t_element	*element;
	t_deque		*stack;

	idx = 2;
	while (--idx >= 0)
	{
		if((stack_idx != AB && stack_idx != idx) || get_st(idx)->size <= 1)
			continue ;
		stack = get_st(idx);
		element = stack->front;
		stack->front = element->next;
		stack->front->before = FT_NULL;
		stack->tail->next = element;
		element->before = stack->tail;
		element->next = FT_NULL;
		stack->tail = element;
	}
	//ft_printf("r" + label[stack_idx] + "\n");
}

void	op_rr(int stack_idx)
{
	const char	label[3] = {'a', 'b', 'r'};
	int			idx;
	t_element	*element;
	t_deque		*stack;

	idx = 2;
	while (--idx >= 0)
	{
		if((stack_idx != AB && stack_idx != idx) || get_st(idx)->size <= 1)
			continue ;
		stack = get_st(idx);
		element = stack->tail;
		stack->tail = element->before;
		element->before->next = FT_NULL;
		element->before = FT_NULL;
		element->next = stack->front;
		stack->front->before = element;
		stack->front = element;
	}
	//ft_printf("rr" + label[stack_idx] + "\n");
}

void	op_s(int stack_idx)
{
	const char	label[3] = {'a', 'b', 's'};
	int			idx;
	t_element	*element;
	t_element	*element2;

	idx = 2;
	while (--idx >= 0)
	{
		if((stack_idx != AB && stack_idx != idx) || get_st(idx)->size <= 1)
			continue ;
		element = get_st(idx)->front;
		element2 = element->next;
		element->before = element2;
		element->next = FT_NULL;
		element->next = element2->next;
		element2->before = FT_NULL;
		element2->next = element;
		get_st(idx)->front = element2;
		if (get_st(idx)->size == 2)
			get_st(idx)->tail = element;
	}
	//ft_printf("rr" + label[stack_idx] + "\n");
}


void	op_p(int stack_idx)
{
	const char	label[2] = {'a', 'b'};
	t_deque		*stack;
	t_deque		*stack2;
	t_element	*element;

	stack = get_st(stack_idx);
	stack2 = get_st((stack_idx + 1) % 2);
	if (stack->size != 0)
	{
		element = stack->front;
		stack->front = element->next;
		stack->front->before = FT_NULL;
		element->next = stack2->front;
		if (stack2->front != FT_NULL)
			stack2->front->before = element;
		stack2->front = element;
		stack->size--;
		stack2->size++;
		if (stack2->size == 1)
			stack2->tail = stack2->front;
	}
	//ft_printf("rr" + label[stack_idx] + "\n");
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