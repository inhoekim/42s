/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 02:25:58 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/03 02:32:18 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_less_3b_sub(int size, t_three_num *t)
{
	t->top = get_st(A)->front->num;
	t->mid = get_st(A)->front->next->num;
	if (size == 2)
	{
		if (t->top < t->mid)
			op_s(B);
		op_p(B);
		op_p(B);
	}
	if (size >= 3)
		t->bottom = get_st(A)->front->next->next->num;
}

void	sort_less_3a(int size)
{
	t_three_num t;

	t.top = get_st(A)->front->num;
	t.mid = get_st(A)->front->next->num;
	if (size == 2)
		if (t.top > t.mid)
			op_s(A);
	if (size == 3)
	{
		t.bottom = get_st(A)->front->next->next->num;
		if (t.top > t.mid && t.mid > t.bottom) // case 3 2 1
			if (!op_s(A) || !op_r(A) || !op_s(A) || !op_p(A) || !op_rr(A) || !op_p(B))
				;
		if (t.top > t.mid && t.mid < t.bottom && t.top > t.bottom)// case 3 1 2
			if (!op_s(A) || !op_r(A) || !op_s(A) || !op_rr(A))
				;
		if (t.top > t.mid && t.mid < t.bottom && t.top < t.bottom)// case 2 1 3
			op_s(A);
		if (t.top < t.mid && t.top > t.bottom)// case 2 3 1
			if (!op_r(A) || !op_s(A) || !op_rr(A) || !op_s(A))
				;
		if (t.top < t.mid && t.top < t.bottom && t.mid > t.bottom)// case 1 3 2
			 if (!op_r(A) || !op_s(A) || !op_rr(A))
			 	;
	}
}

void	sort_less_3b(int size)
{
	t_three_num t;

	sort_less_3b_sub(size, &t);
	if (size >= 3)
	{
		if (t.top > t.mid && t.mid > t.bottom) // case 3 2 1
			if (!op_p(B) || !op_p(B) || !op_p(B))
				;
		if (t.top > t.mid && t.mid < t.bottom && t.top > t.bottom)// case 3 1 2
			if (!op_p(B) || !op_s(B) || !op_p(B) || !op_p(B))
				;
		if (t.top > t.mid && t.mid < t.bottom && t.top < t.bottom)// case 2 1 3
			if (!op_r(B) || !op_s(B) || !op_p(B) || !op_rr(B) || !op_p(B) || !op_p(B))
				;
		if (t.top < t.mid && t.top > t.bottom)// case 2 3 1
			if (!op_s(B) || !op_p(B) || !op_p(B) || !op_p(B))
				;
		if (t.top < t.mid && t.top < t.bottom && t.mid > t.bottom)// case 1 3 2
			 if (!op_r(B) || !op_p(B) || !op_p(B) || !op_rr(B) || !op_p(B))
			 	;
		if (t.top < t.mid && t.top < t.bottom && t.mid < t.bottom)// case 1 2 3
			if (!op_r(B) || !op_s(A) || !op_p(B) || !op_p(B) || !op_rr(B) || !op_p(B))
				;
	}
}