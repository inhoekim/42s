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

static char	*read_line(int idx, t_vector *vec)
{
	char		*ret_str;
	char		*buf;
	long long	offset;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == FT_NULL)
		return (ft_clear(vec->contents, vec->size));
	offset = 0;
	while (1)
	{
		if (ft_find_newline(vec, idx, &offset, &ret_str))
		{
			free(buf);
			return (ret_str);
		}
		if (read(vec->contents[idx].fd, buf, BUFFER_SIZE) == - 1)
			return (ft_clear(vec->contents, vec->size));
		ft_join_buf(vec, idx, buf);
	}
	return (FT_NULL);
}

static int	expand_vector(t_vector *vec)
{
	t_vec_fd	*temp;
	int			idx;

	idx = 0;
	if (vec->size == vec->capacity)
	{
		vec->capacity = vec->capacity * 2;
		temp = vec->contents;
		vec->contents = (t_vec_fd *)malloc(sizeof(t_vec_fd) * vec->capacity);
		if (vec->contents == FT_NULL)
		{
			ft_clear(temp, vec->size);
			return (-1);
		}
		while (idx < vec->size)
		{
			vec->contents[idx].fd = temp[idx].fd;
			vec->contents[idx].str = temp[idx].str;
		}
		free(temp);
	}
	return (FT_TRUE);
}

static int	find_fd(int fd, t_vector *vec)
{
	int	i;

	i = -1;
	while (i < vec->size - 1)
		if (vec->contents[++i].fd == fd)
				break ;
	if (i == vec->size || i == -1)
	{
		if (expand_vector(vec) == FT_ERR)
			return (FT_ERR);
		if (i == -1)
			i = 0;
		vec->contents[i].fd = fd;
		vec->contents[i].str = (char *)malloc(sizeof(char) * 1);
		if (vec->contents[i].str == FT_NULL)
		{
			ft_clear(vec->contents, vec->size);
			return (FT_ERR);
		}
		vec->contents[i].str[0] = '\0';
		vec->size++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static t_vector	fd_vector;
	int				ret;
	int				fd_idx;

	fd_vector.capacity = 1024;
	fd_vector.size = 0;
	fd_vector.contents = (t_vec_fd *)malloc(sizeof(t_vec_fd) * 1024);
	if (fd_vector.contents || fd < 0 || BUFFER_SIZE <= 0)
		return (FT_NULL);
	fd_idx = find_fd(fd, &fd_vector);
	if (fd_idx == FT_ERR)
		return (FT_NULL);
	return (read_line(fd_idx, &fd_vector));
}

int	main(void)
{
	get_next_line(0);
}