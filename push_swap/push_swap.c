/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:49:18 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/03 02:48:25 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	order_stackA(int size, char type)
{
	int area[3];

	if (size <= 3)
	{
		if (size != 1)
			sort_less_3a(size);
		return ;
	}
	partition(A, size, type, area);
	order_stackA(area[2], 'L');
	order_stackB(area[1], 'M');
	move_area(B, area[0]);
	order_stackB(area[0], 'S');
}

void	order_stackB(int size, char type)
{
	int	area[3];

	if (size <= 3)
	{
		if (size == 1)
			op_p(B);
		else
			sort_less_3b(size);
		return ;
	}
	partition(B, size, type, area);
	order_stackA(area[2], 'L');
	move_area(A, area[1]);
	order_stackA(area[1], 'M');
	order_stackB(area[0], 'S');
}


int	main(int argc, char **argv)
{
	if (check_format(argc, argv) == FT_ERR || \
	chk_dup(mrg_sort(mk_arr(A, get_st(A)->size), get_st(A)->size)) == FT_ERR)
	{
		printf("Error\n");
		exit(1);
	}
	order_stackA(get_st(A)->size, 'L');
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
