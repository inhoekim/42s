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
#  define BUFFER_SIZE 42
# endif
#include <unistd.h>
typedef struct s_lst_fd{
	struct s_lst_fd	*next;
	struct s_lst_fd	*head;
	struct s_lst_fd	*tail;
	int				fd;
}t_lst_fd;
char	*get_next_line(int fd);
#endif
