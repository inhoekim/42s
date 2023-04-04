/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:47:14 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/31 10:47:16 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long long	ft_putstr_fd(char *str, long long len, int fd)
{
	long long	cnt;
	long long	temp;
	int			idx;

	cnt = 0;
	idx = 0;
	while (str[idx] && len > idx)
	{
		temp = write(fd, &str[idx], 1);
		if (temp < 0)
			return (-1);
		cnt += temp;
		idx++;
	}
	return (cnt);
}
