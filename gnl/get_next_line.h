/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:30:33 by inhkim            #+#    #+#             */
/*   Updated: 2023/04/10 18:30:33 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# define FT_NULL 0
# define FT_ERR -1
# define FT_TRUE 1
# define FT_FALSE 0
#include <unistd.h>
typedef struct s_vec_fd{
	int		fd;
	char	*str;
}t_vec_fd;
typedef struct s_vector{
	long long	capacity;
	int			size;
	t_vec_fd	*contents;
}t_vector;
char	*get_next_line(int fd);
int	ft_find_newline(t_vector *vec, \
int idx, long long *offset, char **ret_str);
int	ft_split_newline(t_vector *vec, \
int idx, long long offset, char **ret_str);
void	ft_str_copy(char *dest, \
char *src, long long start, long long end);
long long	ft_strlen(char *str);
void	*ft_clear(t_vec_fd *contents, int size);
#endif
