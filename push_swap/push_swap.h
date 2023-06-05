/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:48:15 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/06 08:00:33 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
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
typedef struct s_part_info
{
	int			idx;
	int			pivot;
	int			pivot2;
	int			remain_l;
	int			remain_m;
	int			remain_s;
	int			*arr;
}t_part_info;
typedef struct s_three_num
{
	int	top;
	int	mid;
	int	bottom;
}t_three_num;
int			op_r(int stack_idx);
int			op_rr(int stack_idx);
int			op_s(int stack_idx);
int			op_p(int stack_idx);
int			push_back(t_deque *stack, int val);
t_deque		*get_st(int type);
int			check_format(int argc, char **argv);
int			chk_dup(int *arr);
int			*mk_arr(int stack_idx, int size);
void		move_area(int stack_idx, int area_size, int rr_size);
int			*mrg_sort(int *arr, int size);
int			partition(int from, int size, int *area);
long long	ft_atoi(const char *str);
char		**ft_split(const char *s);
void		sort_less_3a(int size);
void		sort_less_3b(int size);
void		emp_sort_less_4a(int size);
void		emp_sort_less_4b(int size);
void		emp_sort_4a();
void		emp_sort_4b();
int			sorted_check(int from, int size, t_part_info *info);
void		order_stack_a(int size);
void		order_stack_b(int size);
#endif
