/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:48:15 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/01 04:32:42 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# ifdef __x86_64__ 
#  define FT_LONG_MAX 9223372036854775807L
# else
#  define FT_LONG_MAX 2147483647L
# endif
# define FT_INT_MAX 2147483647
# define FT_NULL 0
# define FT_ERR 0
# define FT_TRUE 1
# define A 0
# define B 1
# define AB 2

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
	int 				size;
}t_deque;
typedef struct	s_format_info
{
	char	**splited_str;
	int		idx;
	long	num;
	int		i;
}t_format_info;
void	oper_r(int stack_idx, t_deque (*stacks)[2]);
long	ft_atoi(const char *str);
char	**ft_split(const char *s);
t_deque	*get_st(int type);
int		*merge_sort(int *arr, int size);
int		check_dup(int *arr);
#endif
