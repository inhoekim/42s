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

void	oper_r(int stack_idx, t_deque	(*stacks)[2])
{
	t_element	*element;
	int			idx;

	idx = 2;
	while (--idx > -1)
	{
		if(stack_idx != AB && stack_idx != idx)
			continue ;
		element = stacks[idx]->front;
		stacks[idx]->front = element->next;
		stacks[idx]->front->before = FT_NULL;
		stacks[idx]->tail->next = element;
		element->before = stacks[idx]->tail;
		element->next = FT_NULL;
		stacks[idx]->tail = element;
		//ft_printf("ra\n");
	}
}

/*
void	rb(t_deque* stack)
{
	t_element* element;

	element = stack->front;
	stack->front = element->next;
	stack->front->before = FT_NULL;
	stack->tail->next = element;
	element->before = stack->tail;
	element->next = FT_NULL;
	stack->tail = element;
	ft_printf("rb\n");
}



void	pa(t_deque* stack_a, t_deque* stack_b) {
	t_deque* move_element;

	move_element = stack_a->front;
	dq_pop_front(stack_a);
	dq_push_front(stack_b, move_element);
	ft_printf("pa\n");
}

void	rra(int stack_idx) {
	int move_num = dqs[stack_idx].back();
	dqs[stack_idx].pop_back();
	dqs[stack_idx].push_front(move_num);
	ss << "RRO " << stack_idx << "\n";
	cnt++;
}
*/