/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:56:20 by inhkim            #+#    #+#             */
/*   Updated: 2023/10/08 13:00:05 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

int	check_pid(char *pid_str)
{
	int		idx;
	pid_t	pid;

	idx = -1;
	pid = 0;
	while (pid_str[++idx])
	{
		if (!ft_isdigit(pid_str[idx]) || pid > 10000)
		{
			ft_putendl_fd("[Error] incorrect PID ", 2);
			exit(1);
		}
		pid = (pid * 10) + pid_str[idx] - '0';
	}
	if (pid <= 100)
	{
		ft_putendl_fd("[Error] incorrect PID ", 2);
		exit(1);
	}
	return (0);
}
