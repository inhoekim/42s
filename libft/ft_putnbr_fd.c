/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 03:16:50 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/19 03:16:51 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:23:07 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/18 18:23:09 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	recur_write(long long num, int fd)
{
	char	ch_num;

	if (num / 10 == 0)
	{
		ch_num = (num % 10) + '0';
		write(fd, &ch_num, 1);
		return ;
	}
	recur_write(num / 10, fd);
	ch_num = (num % 10) + '0';
	write(fd, &ch_num, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	num;

	num = (long long)n;
	if (num < 0)
	{
		num *= -1;
		write (fd, "-", 1);
	}
	recur_write(num, fd);
}
