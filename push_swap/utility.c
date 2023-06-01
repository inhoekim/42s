/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 01:57:52 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/01 03:35:30 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_deque	*get_st(int type)
{
	static t_deque	stacks[2];

	if (type == A)
		return (&stacks[A]);
	if (type == B)
		return (&stacks[B]);
}

int	check_dup(int *arr)
{
	int i;

	if (arr == FT_NULL)
		return (FT_ERR);
	i = 0;
	while (i < get_st(A)->size - 1)
	{
		if (arr[i] == arr[i + 1])
			return (FT_ERR);
		i++;
	}
	free(arr);
	return (FT_TRUE);
}