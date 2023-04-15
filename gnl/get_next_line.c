/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:30:14 by inhkim            #+#    #+#             */
/*   Updated: 2023/04/16 05:03:08 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	join_buf(t_vector *vec, int idx, char *buf)
{
	char		*temp_str;
	long long	new_size;
	long long	str_idx;
	long long	buf_idx;

	temp_str = vec->contents[idx].str;
	new_size = ft_strlen(temp_str) + ft_strlen(buf);
	vec->contents[idx].str = (char *)malloc(sizeof(char) * (new_size + 1));
	if (!vec->contents[idx].str)
	{
		free(temp_str);
		return (FT_ERR);
	}
	str_idx = -1;
	while (++str_idx < ft_strlen(temp_str))
		vec->contents[idx].str[str_idx] = temp_str[str_idx];
	buf_idx = 0;
	while (str_idx < new_size)
		vec->contents[idx].str[str_idx++] = buf[buf_idx++];
	vec->contents[idx].str[str_idx] = '\0';
	free(temp_str);
	return (FT_TRUE);
}

static char	*read_line(int idx, t_vector *vec)
{
	char		*ret_str;
	char		*buf;
	long long	offset;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == FT_NULL)
		return (ft_clear(vec->contents, vec->size));
	offset = 0;
	while (FT_TRUE)
	{
		if (ft_find_newline(vec, idx, &offset, &ret_str))
		{
			free(buf);
			return (ret_str);
		}
		if (read(vec->contents[idx].fd, buf, BUFFER_SIZE) == FT_ERR)
			return (ft_clear(vec->contents, vec->size));
		if (join_buf(vec, idx, buf) == FT_ERR)
			return (ft_clear(vec->contents, vec->size));
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
	int				fd_idx;

	if (fd_vector.size == 0)
	{
		fd_vector.capacity = 1024;
		fd_vector.size = 0;
		fd_vector.contents = (t_vec_fd *)malloc(sizeof(t_vec_fd) * 1024);
	}
	if (!fd_vector.contents || fd < 0 || BUFFER_SIZE <= 0)
		return (FT_NULL);
	fd_idx = find_fd(fd, &fd_vector);
	if (fd_idx == FT_ERR)
		return (FT_NULL);
	return (read_line(fd_idx, &fd_vector));
}
