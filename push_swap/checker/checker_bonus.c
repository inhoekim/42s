/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:39:44 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/12 19:43:00 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap_bonus.h"

static int	proc_stack_op_sub(char *s)
{
	if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && s[3] == '\n')
		return (op_rr(A));
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && s[3] == '\n')
		return (op_rr(B));
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && s[3] == '\n')
		return (op_rr(AB));
	else if (s[0] == 's' && s[1] == 'a'&& s[2] == '\n')
		return (op_rr(A));
	else if (s[0] == 's' && s[1] == 'a' && s[2] == '\n')
		return (op_rr(B));
	else if (s[0] == 's' && s[1] == 's' && s[2] == '\n')
		return (op_rr(B));
	else
		return (FT_ERR);
}

static int	proc_stack_op(char *s)
{
	if (s[0] == 'p' && s[1] == 'a' && s[2] == '\n')
		return (op_p(B));
	else if (s[0] == 'p' && s[1] == 'b' && s[2] == '\n')
		return (op_p(A));
	else if (s[0] == 'r' && s[1] == 'a' && s[2] == '\n')
		return (op_p(A));
	else if (s[0] == 'r' && s[1] == 'b' && s[2] == '\n')
		return (op_p(B));
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == '\n')
		return (op_p(AB));
	else
		return (proc_stack_op_sub(s));
}

static int	read_oper(void)
{
	char	*str;

	str = get_next_line(0);
	while (str != FT_NULL)
	{
		if (proc_stack_op(str) == FT_ERR)
		{
			free(str);
			return (FT_ERR);
		}
		free(str);
		str = get_next_line(0);
	}
	return (FT_TRUE);
}

int main(int argc, char **argv)
{
	int *arr;

	if (argc <= 1)
		return (0);
	if (check_format(argc, argv) == FT_ERR || \
	chk_dup(mrg_sort(arr, get_st(A)->size)) == FT_ERR\
	 || read_oper() == FT_ERR)	
	{
		write(2, "Error\n", 6);
		clear_stack();
		exit(1);
	}
	if (get_st(B)->size != 0 || sorted_check(arr))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(arr);
	clear_stack();
	return (0);
}
