/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:04:22 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/06 00:27:26 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	proc_part_from_b(t_part_info *info)
{
	int		front_num;

	front_num = get_st(B)->front->num;
	if (front_num < info->pivot && \
	!(info->remain_m == 0 && info->remain_l == 0))
	{
		op_r(B);
		info->remain_s--;
	}
	else if (info->pivot <= front_num && front_num < info->pivot2)
	{
		op_p(B);
		op_r(A);
		info->remain_m--;
	}
	else if (front_num >= info->pivot2)
	{
		op_p(B);
		info->remain_l--;
	}
}

static void	proc_part_from_a(t_part_info *info)
{
	int		front_num;

	front_num = get_st(A)->front->num;
	if (front_num < info->pivot)
	{
		op_p(A);
		op_r(B);
		info->remain_s--;
	}
	else if (info->pivot <= front_num && front_num < info->pivot2)
	{
		op_p(A);
		info->remain_m--;
	}
	else if (front_num >= info->pivot2 && \
	!(info->remain_s == 0 && info->remain_m == 0))
	{
		op_r(A);
		info->remain_l--;
	}
}

static void	init_part(t_part_info *info, int from, int size, int *area)
{
	info->arr = mrg_sort(mk_arr(from, size), size);
	info->pivot = info->arr[size / 3];
	info->pivot2 = info->arr[(size / 3) * 2];
	area[0] = size / 3;
	info->remain_s = area[0];
	area[1] = size / 3;
	info->remain_m = area[1];
	area[2] = size / 3 + size % 3;
	info->remain_l = area[2];
	info->idx = -1;
}

int	partition(int from, int size, int *area)
{
	t_part_info	info;
	int			is_sorted;

	init_part(&info, from, size, area);
	is_sorted = sorted_check(from, size, &info);
	if ((is_sorted == -1 && from == B) || (is_sorted == 1 && from == A))
	{
		free(info.arr);
		return (is_sorted);
	}
	if (from == A)
	{
		while (++(info.idx) < size)
			proc_part_from_a(&info);
		move_area(A, area[2] - info.remain_l);
	}
	else if (from == B)
	{
		while (++(info.idx) < size)
			proc_part_from_b(&info);
		move_area(B, area[0] - info.remain_s);
	}
	free(info.arr);
	return (is_sorted);
}

void	move_area(int stack_idx, int area_size)
{
	int	idx;
	int	static_area_size;

	idx = -1;
	static_area_size = get_st(stack_idx)->size;
	if (2 * area_size < area_size)
		while (++idx < static_area_size)
			op_rr(stack_idx);
	else
		while (++idx < static_area_size - area_size)
			op_r(stack_idx);
}
