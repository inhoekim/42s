/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:30:14 by inhkim            #+#    #+#             */
/*   Updated: 2023/04/18 09:28:44 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	join_buf(t_vector *vec, int idx, char *buf, long long buf_len)
{
	t_vector	*str_vec;
	long long	new_size;
	long long	i;

	str_vec = &(vec->inner_vec[idx]);
	new_size = str_vec->size + buf_len + 1;
	while (str_vec->capacity <= new_size || !str_vec->str)
		if (ft_expand_vector(&(vec->inner_vec[idx])) == FT_ERR)
			return (FT_ERR);
	i = -1;
	while (++i < buf_len)
		str_vec->str[str_vec->size + i] = buf[i];
	str_vec->str[str_vec->size + i] = '\0';
	str_vec->size += buf_len;
	return (FT_TRUE);
}

static int	read_check(long long read_ret, \
int idx, t_vector *vec, char **ret_str)
{
	if (read_ret == FT_FALSE && vec->inner_vec[idx].str)
	{
		ft_split_newline(vec, idx, vec->inner_vec[idx].size - 1, ret_str);
		free(vec->inner_vec[idx].str);
		vec->size--;
		vec->inner_vec[idx] = vec->inner_vec[vec->size];
		return (FT_TRUE);
	}
	if (read_ret <= 0)
	{
		free(vec->inner_vec[idx].str);
		vec->size--;
		vec->inner_vec[idx] = vec->inner_vec[vec->size];
		return (FT_TRUE);
	}
	return (FT_FALSE);
}

static int	read_line(int idx, t_vector *vec, char **ret_str, char **buf)
{
	long long	offset;
	ssize_t		read_ret;

	*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (*buf == FT_NULL)
		return (FT_ERR);
	(*buf)[BUFFER_SIZE] = '\0';
	offset = 0;
	while (FT_TRUE)
	{
		while (vec->inner_vec[idx].str && vec->inner_vec[idx].str[offset])
			if (vec->inner_vec[idx].str[++offset - 1] == '\n')
				return (ft_split_newline(vec, idx, offset - 1, ret_str));
		read_ret = read(vec->inner_vec[idx].fd, *buf, BUFFER_SIZE);
		if (read_check(read_ret, idx, vec, ret_str))
			return (FT_TRUE);
		if (join_buf(vec, idx, *buf, (long long)read_ret) == FT_ERR)
			return (FT_ERR);
	}
}

static int	find_fd(int fd, t_vector *vec)
{
	int	i;

	i = -1;
	if (fd < 0)
		return (i);
	while (++i < vec->size)
		if (vec->inner_vec[i].fd == fd)
			break ;
	if (i == vec->size || i == -1)
	{
		if (ft_expand_outer_vector(vec) == FT_ERR)
			return (FT_ERR);
		if (i == -1)
			i = 0;
		vec->inner_vec[i].fd = fd;
		vec->inner_vec[i].capacity = 1024;
		vec->inner_vec[i].size = 0;
		vec->inner_vec[i].str = FT_NULL;
		vec->size++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static t_vector	outer_vector;
	t_data			dat;

	if (outer_vector.size == 0)
	{
		outer_vector.capacity = 1024;
		outer_vector.size = 0;
		outer_vector.inner_vec = (t_vector *)malloc(sizeof(t_vector) * 1024);
		if (outer_vector.inner_vec == FT_NULL)
			return (FT_NULL);
	}
	dat.fd_idx = find_fd(fd, &outer_vector);
	if (dat.fd_idx == FT_ERR || BUFFER_SIZE <= 0)
	{
		free(outer_vector.inner_vec);
		return (FT_NULL);
	}
	dat.str = FT_NULL;
	if (read_line(dat.fd_idx, &outer_vector, &(dat.str), &(dat.buf)) == FT_ERR)
	{
		free(outer_vector.inner_vec);
		return (dat.str);
	}
	free(dat.buf);
	if (outer_vector.size == 0)
		free(outer_vector.inner_vec);
	return (dat.str);
}
