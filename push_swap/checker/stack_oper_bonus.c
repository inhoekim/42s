/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_oper_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:58:43 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/12 19:40:39 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	op_r(int stack_idx)
{
	int			idx;
	t_element	*element;
	t_deque		*stack;

	idx = 2;
	while (--idx >= 0)
	{
		if ((stack_idx != AB && stack_idx != idx) || get_st(idx)->size <= 1)
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
	return (FT_TRUE);
}

int	op_rr(int stack_idx)
{
	int			idx;
	t_element	*element;
	t_deque		*stack;

	idx = 2;
	while (--idx >= 0)
	{
		if ((stack_idx != AB && stack_idx != idx) || get_st(idx)->size <= 1)
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
	return (FT_TRUE);
}

int	op_s(int stack_idx)
{
	int			idx;
	t_element	*element;
	t_element	*element2;

	idx = 2;
	while (--idx >= 0)
	{
		if ((stack_idx != AB && stack_idx != idx) || get_st(idx)->size <= 1)
			continue ;
		element = get_st(idx)->front;
		element2 = element->next;
		element->before = element2;
		element->next = element2->next;
		if (element->next != FT_NULL)
			element->next->before = element;
		element2->before = FT_NULL;
		element2->next = element;
		get_st(idx)->front = element2;
		if (get_st(idx)->size == 2)
			get_st(idx)->tail = element;
	}
	return (FT_TRUE);
}

static void	op_p_sub(t_deque *stack, t_deque *stack2)
{
	t_element	*element;

	if (stack->size != 0)
	{
		element = stack->front;
		stack->front = element->next;
		if (stack->front != FT_NULL)
			stack->front->before = FT_NULL;
		else
			stack->tail = FT_NULL;
		element->next = stack2->front;
		if (stack2->front != FT_NULL)
			stack2->front->before = element;
		else
			stack2->tail = element;
		stack2->front = element;
		stack->size--;
		stack2->size++;
		if (stack2->size == 1)
			stack2->tail = stack2->front;
	}
}

int	op_p(int stack_idx)
{
	t_deque		*stack;
	t_deque		*stack2;

	stack = get_st(stack_idx);
	stack2 = get_st((stack_idx + 1) % 2);
	op_p_sub(stack, stack2);
	return (FT_TRUE);
}
