/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:33:30 by inhkim            #+#    #+#             */
/*   Updated: 2023/04/18 06:03:37 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# define FT_NULL 0
# define FT_ERR -1
# define FT_TRUE 1
# define FT_FALSE 0
# include <unistd.h>
# include <stdlib.h>

typedef struct s_vector{
	long long		capacity;
	int				size;
	int				fd;
	char			*str;
	struct s_vector	*inner_vec;
}t_vector;
typedef struct s_data{
	int		fd_idx;
	char	*str;
	char	*buf;
}t_data;
char	*get_next_line(int fd);
int		ft_split_newline(t_vector *vec, \
int idx, long long offset, char **ret_str);
void	ft_str_copy(char *dest, \
char *src, long long start, long long end);
int		ft_expand_outer_vector(t_vector *vec);
int		ft_expand_vector(t_vector *vec);
void	ft_all_clear(t_vector *vec);
#endif