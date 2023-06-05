/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 02:25:58 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/06 06:04:50 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_less_3b_sub(t_three_num t)
{
	if (t.top > t.mid && t.mid > t.bottom)
		if (!op_p(B) || !op_p(B) || !op_p(B))
			;
	if (t.top > t.mid && t.mid < t.bottom && t.top > t.bottom)
		if (!op_p(B) || !op_s(B) || !op_p(B) || !op_p(B))
			;
	if (t.top > t.mid && t.mid < t.bottom && t.top < t.bottom)
		if (!op_r(B) || !op_s(B) || \
		!op_p(B) || !op_rr(B) || !op_p(B) || !op_p(B))
			;
	if (t.top < t.mid && t.top > t.bottom)
		if (!op_s(B) || !op_p(B) || !op_p(B) || !op_p(B))
			;
	if (t.top < t.mid && t.top < t.bottom && t.mid > t.bottom)
		if (!op_r(B) || !op_p(B) || !op_p(B) || !op_rr(B) || !op_p(B))
			;
	if (t.top < t.mid && t.top < t.bottom && t.mid < t.bottom)
		if (!op_r(B) || !op_s(B) || \
		!op_p(B) || !op_p(B) || !op_rr(B) || !op_p(B))
			;
}

static void	sort_less_3a_sub(t_three_num t)
{
	if (t.top > t.mid && t.mid > t.bottom)
		if (!op_s(A) || !op_r(A) || !op_s(A) || !op_rr(A) || !op_s(A))
			;
	if (t.top > t.mid && t.mid < t.bottom && t.top > t.bottom)
		if (!op_s(A) || !op_r(A) || !op_s(A) || !op_rr(A))
			;
	if (t.top > t.mid && t.mid < t.bottom && t.top < t.bottom)
		op_s(A);
	if (t.top < t.mid && t.top > t.bottom)
		if (!op_r(A) || !op_s(A) || !op_rr(A) || !op_s(A))
			;
	if (t.top < t.mid && t.top < t.bottom && t.mid > t.bottom)
		if (!op_r(A) || !op_s(A) || !op_rr(A))
			;
}

void	sort_less_3a(int size)
{
	t_three_num	t;

	t.top = get_st(A)->front->num;
	t.mid = get_st(A)->front->next->num;
	if (size == 2)
		if (t.top > t.mid)
			op_s(A);
	if (size == 3)
	{
		t.bottom = get_st(A)->front->next->next->num;
		sort_less_3a_sub(t);
	}
}

void	sort_less_3b(int size)
{
	t_three_num	t;

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
		sort_less_3b_sub(t);
	}
}

int	sorted_check(int from, int size, t_part_info *info)
{
	t_element	*iter;
	int			idx;
	int			flag;

	flag = 1;
	idx = -1;
	iter = get_st(from)->front;
	while (++idx < size)
	{
		if (info->arr[idx] != iter->num)
			flag = 0;
		iter = iter->next;
	}
	if (flag)
		return (1);
	iter = get_st(from)->front;
	while (--size >= 0)
	{
		if (info->arr[size] != iter->num)
			flag = 1;
		iter = iter->next;
	}
	if (!flag)
		return (-1);
	return (2);
}
