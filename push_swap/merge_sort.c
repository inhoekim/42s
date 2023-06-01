/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 03:16:16 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/01 05:20:56 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	merge(int *arr, int *new_arr, int left, int right)
{
	int	left_arr_idx;
	int	right_arr_idx;
	int idx;

	idx = left;
	left_arr_idx = left;
	right_arr_idx = (left + right) / 2 + 1;
	while (left_arr_idx <= (left + right) / 2 || right_arr_idx <= right)
	{
		if (left_arr_idx > (left + right) / 2)
			new_arr[idx++] = arr[right_arr_idx++];
		else if (right_arr_idx > right)
			new_arr[idx++] = arr[left_arr_idx++];
		else
		{
			if (arr[left_arr_idx] >= arr[right_arr_idx])
				new_arr[idx++] = arr[right_arr_idx++];
			else
				new_arr[idx++] = arr[left_arr_idx++];
		}
	}
	left--;
	while (++left <= right)
		arr[left] = new_arr[left];
}

void	merge_proc(int *arr, int *new_arr, int left, int right)
{
	int mid;

	if (left >= right)
		return ;
	mid = (left + right) / 2;
	merge_proc(arr, new_arr, left, mid);
	merge_proc(arr, new_arr, mid + 1, right);
	merge(arr, new_arr, left, right);
}

int *merge_sort(int *arr, int size)
{
	int *new_arr;

	if (size == 1)
		return (arr);
	new_arr = (int *)malloc(sizeof(int) * size);
	if (arr == FT_NULL || new_arr == FT_NULL)
		return (FT_NULL);
	merge_proc(arr, new_arr, 0, size - 1);
	free(arr);
	return (new_arr);
}


