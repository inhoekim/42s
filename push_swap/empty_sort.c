/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:15:00 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/06 05:48:10 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3a_sub(t_three_num t)
{
	if (t.top > t.mid && t.mid > t.bottom)
		if (!op_r(A) || !op_s(A))
			;
	if (t.top > t.mid && t.mid < t.bottom && t.top > t.bottom)
		if (!op_r(A))
			;
	if (t.top > t.mid && t.mid < t.bottom && t.top < t.bottom)
		if (!op_s(A))
			;
	if (t.top < t.mid && t.top > t.bottom)
		if (!op_rr(A))
			;
	if (t.top < t.mid && t.top < t.bottom && t.mid > t.bottom)
		if (!op_rr(A) || !op_s(A))
			;
}

static void	sort_3b_sub(t_three_num t)
{
	if (t.top > t.mid && t.mid > t.bottom)
		if (!op_p(B) || !op_p(B) || !op_p(B))
			;
	if (t.top > t.mid && t.mid < t.bottom && t.top > t.bottom)
		if (!op_p(B) || !op_s(B) || !op_p(B) || !op_p(B))
			;
	if (t.top > t.mid && t.mid < t.bottom && t.top < t.bottom)
		if (!op_rr(B) || !op_p(B) || !op_p(B) || !op_p(B))
			;
	if (t.top < t.mid && t.top > t.bottom)
		if (!op_s(B) || !op_p(B) || !op_p(B) || !op_p(B))
			;
	if (t.top < t.mid && t.top < t.bottom && t.mid > t.bottom)
		if (!op_r(B) || !op_p(B) || !op_p(B) || !op_p(B))
			;
	if (t.top < t.mid && t.top < t.bottom && t.mid < t.bottom)
		if (!op_s(B) || !op_rr(B) || !op_p(B) || !op_p(B) || !op_p(B))
			;
}

void	emp_sort_less_4a(int size)
{
	t_three_num	t;

	if (size == 4)
	{
		emp_sort_4a();
		sort_less_3a(3);
		return ;
	}
	t.top = get_st(A)->front->num;
	t.mid = get_st(A)->front->next->num;
	if (size == 2)
		if (t.top > t.mid)
			op_s(A);
	if (size == 3)
	{
		t.bottom = get_st(A)->front->next->next->num;
		sort_3a_sub(t);
	}
}

void	emp_sort_less_4b(int size)
{
	t_three_num	t;

	if (size == 4)
	{
		emp_sort_4b();
		size--;
	}
	t.top = get_st(B)->front->num;
	t.mid = get_st(B)->front->next->num;
	if (size == 2)
	{
		if (t.top < t.mid)
			op_s(B);
		op_p(B);
		op_p(B);
	}
	if (size >= 3)
	{
		t.bottom = get_st(B)->front->next->next->num;
		sort_3b_sub(t);
	}
}