/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:49:18 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/12 11:31:47 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	check_two(int stack_idx)
{
	int	head_num;
	int	next_num;

	head_num = get_st(stack_idx)->front->num;
	next_num = get_st(stack_idx)->front->next->num;
	if (head_num < next_num)
		op_s(stack_idx);
}

void	order_stack_a(int size)
{
	int	area[3];

	if (size == 1)
		return ;
	if (size <= 4 && get_st(A)->size <= 4)
	{
		emp_sort_less_4a(size);
		return ;
	}
	if (size <= 3 && get_st(A)->size > 4)
	{
		sort_less_3a(size);
		return ;
	}
	if (partition(A, size, area) == 1)
		return ;
	order_stack_a(area[2]);
	if (size == 5)
		check_two(B);
	order_stack_b(area[1]);
	if (size != 5)
		move_area(B, area[0]);
	order_stack_b(area[0]);
}

void	order_stack_b(int size)
{
	int	area[3];

	if (size == 1)
	{
		op_p(B);
		return ;
	}
	if (size <= 4 && get_st(B)->size <= 4)
		return (emp_sort_less_4b(size));
	if (size <= 3 && get_st(B)->size > 4)
		return (sort_less_3b(size));
	if (partition(B, size, area) == -1)
	{
		while (size--)
			op_p(B);
		return ;
	}
	order_stack_a(area[2]);
	move_area(A, area[1]);
	order_stack_a(area[1]);
	order_stack_b(area[0]);
}

static void	clear_stack(void)
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

int	main(int argc, char **argv)
{	
	if (argc <= 1)
		return (0);
	if (check_format(argc, argv) == FT_ERR || \
	chk_dup(mrg_sort(mk_arr(A, get_st(A)->size), get_st(A)->size)) == FT_ERR)
	{
		write(2, "Error\n", 6);
		clear_stack();
		exit(1);
	}
	order_stack_a(get_st(A)->size);
	clear_stack();
	return (0);
}
