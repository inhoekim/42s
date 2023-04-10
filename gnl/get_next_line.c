/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:30:14 by inhkim            #+#    #+#             */
/*   Updated: 2023/04/10 18:30:15 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	ssize_t		read_size;
	t_lst_fd	lst;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read_size = read(fd, buf, BUFFER_SIZE);
	
}
