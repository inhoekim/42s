/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:56:03 by inhkim            #+#    #+#             */
/*   Updated: 2023/10/08 20:49:07 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

volatile sig_atomic_t	g_lock;

static void	timer_lock(void)
{
	int	idx;

	idx = 0;
	while (g_lock && idx != TIME_OUT)
		idx++;
	if (idx == TIME_OUT)
	{
		ft_putendl_fd("Time session has expired. Shut down the communication.", \
		1);
		exit(1);
	}
}

static int	check_pid(char *pid_str)
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

static void	recieve_handler(int sig, \
struct __siginfo *sif, void *none)
{
	(void) sif;
	(void) none;
	if (sig == SIGUSR1)
		g_lock = 0;
	else
	{
		ft_putendl_fd("\nThe server is busy. Please try later!!!", 2);
		exit(1);
	}
}

static void	send_message(pid_t pid, const char *msg)
{
	int	idx;
	int	bit_offset;

	idx = -1;
	while (msg[++idx])
	{
		bit_offset = -1;
		while (++bit_offset < 8)
		{
			g_lock = 1;
			usleep(50);
			if ((msg[idx] >> bit_offset) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			timer_lock();
		}
	}
	idx = -1;
	while (++idx < 8)
	{
		g_lock = 1;
		usleep(50);
		kill(pid, SIGUSR2);
		timer_lock();
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sigact;

	sigact.sa_sigaction = &recieve_handler;
	sigemptyset(&sigact.sa_mask);
	sigaddset(&sigact.sa_mask, SIGUSR1);
	sigaddset(&sigact.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	if (argc == 3 && argv[2][0] != '\0')
	{
		check_pid(argv[1]);
		g_lock = 0;
		send_message(ft_atoi(argv[1]), argv[2]);
		ft_putendl_fd("Transmission is success!", 1);
	}
	else
	{
		ft_putendl_fd("[misusage] usage: ./client PID NON_EMPTY_STRING", 2);
		return (1);
	}
	return (0);
}
