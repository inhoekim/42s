/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:48:15 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/19 14:47:47 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define FT_LONG_MAX 9223372036854775807L
# define FT_INT_MAX 2147483647
# define FT_NULL 0
# define FT_ERR 0
# define FT_TRUE 1
# define A 0
# define B 1
# define AB 2
# include <stdlib.h>

typedef struct s_element
{
	struct s_element	*before;
	struct s_element	*next;
	int					num;
}t_element;
typedef struct s_deque
{
	struct s_element	*front;
	struct s_element	*tail;
	int					size;
}t_deque;
typedef struct s_format_info
{
	char		**splited_str;
	int			idx;
	int			i;
	long long	num;
}t_format_info;
int			op_r(int stack_idx);
int			op_rr(int stack_idx);
int			op_s(int stack_idx);
int			op_p(int stack_idx);
t_deque		*get_st(int type);
int			check_format(int argc, char **argv);
int			chk_dup(int **arr);
int			**mk_arr(int **arr, int size);
int			**mrg_sort(int **arr, int size);
int			push_back(t_deque *stack, int val);
void		clear_stack(void);
int			sorted_check(int *arr);
long long	ft_atoi(const char *str);
char		**ft_split(const char *s);
char		*get_next_line(int fd);
#endif
