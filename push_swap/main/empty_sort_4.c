/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_sort_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 05:01:12 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/07 08:02:19 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max(int stack_idx)
{
	int			max;
	t_element	*iter;
	int			idx;
	int			max_idx;

	iter = get_st(stack_idx)->front;
	max = iter->num;
	max_idx = 0;
	idx = 0;
	while (idx < 4)
	{
		if (max < iter->num)
		{
			max = iter->num;
			max_idx = idx;
		}
		iter = iter->next;
		idx++;
	}
	return (max_idx);
}

void	emp_sort_4a(void)
{
	int	idx;

	idx = find_max(A);
	if (idx == 0)
		op_r(A);
	if (idx == 1)
		if (!op_s(A) || !op_r(A))
			;
	if (idx == 2)
		op_rr(A);
}

void	emp_sort_4b(void)
{
	int	idx;

	idx = find_max(B);
	if (idx == 1)
		op_s(B);
	if (idx == 2)
		if (!op_rr(B) || !op_rr(B))
			;
	if (idx == 3)
		op_rr(B);
	op_p(B);
}
