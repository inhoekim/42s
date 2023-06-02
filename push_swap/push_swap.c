/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:49:18 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/02 18:04:03 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

static void	order_stack(int from, int size, char type)
{
	int* const	area = {0, 0, 0};

	if (size <= 3)
	{
		//sort_less_3(from, size, type);
		return ;
	}
	partition(from, size, type, area);
	if (from == A)
	{
		order_stack(A, area[2], 'L');
		order_stack(B, area[1], 'M');
		move_area(B, area[0]);
		order_stack(B, area[0], 'S');
	}
	if (from == B)
	{
		order_stack(A, area[2], 'L');
		move_area(A, area[1]);
		order_stack(A, area[1], 'M');
		order_stack(B, area[0], 'S');
	}
}


int	main(int argc, char **argv)
{
	if (check_format(argc, argv) == FT_ERR || \
	chk_dup(mrg_sort(mk_arr(A, get_st(A)->size), get_st(A)->size)) == FT_ERR)
	{
		printf("Error\n");
		exit(1);
	}
	order_stack(A, get_st(A)->size, 'L');

	/*
	printf("stackA");
	printf("\n===================================\n");
	int *arr = mk_arr(A, get_st(A)->size);
	for (int i = 0; i < get_st(A)->size; i++)
		printf("%d ", arr[i]);
	printf("\n===================================\n");
	printf("stackB");
	printf("\n===================================\n");
	arr = mk_arr(B, get_st(B)->size);
	for (int i = 0; i < get_st(B)->size; i++)
		printf("%d ", arr[i]);
	printf("\n===================================\n");
	*/
	return (0);
}
