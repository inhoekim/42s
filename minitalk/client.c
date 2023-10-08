/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:56:03 by inhkim            #+#    #+#             */
/*   Updated: 2023/10/08 14:18:55 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"
#include <stdio.h>

volatile sig_atomic_t g_lock;

void	recieve_handler(int sig, \
struct __siginfo *sif, void *none)
{
	(void) sif;
	(void) none;
	if (sig == SIGUSR1)
		g_lock = 0;
	else
	{
		ft_putendl_fd("Your Message is Missing for some reason. \
		Please resend!", 2);
		exit(1);
	}
}

void	send_message(pid_t pid, const char *msg)
{
	int	idx;
	int	bit_offset;

	idx = -1;
	while (msg[++idx])
	{
		bit_offset = -1;
		while (++bit_offset < 8)
		{
			usleep(10);
			g_lock = 1;
			if ((msg[idx] >> bit_offset) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (g_lock)
				;
		}
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
