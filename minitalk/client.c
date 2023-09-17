/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:56:03 by inhkim            #+#    #+#             */
/*   Updated: 2023/09/17 20:22:18 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

void	recieve_handler(int sig, \
struct __siginfo *sip, void *none)
{
	(void)sig;(void)sip;(void)none;
	exit(0);
}

void	send_message(void)
{
	exit(0);
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
		if (check_pid(argv[1]))
			exit(1);
		kill(ft_atoi(argv[1]), SIGUSR1);
		while (1)
			;
	}
	else
	{
		ft_putendl_fd("[misusage] usage: ./client PID NON_EMPTY_STRING", 2);
		return (1);
	}
	return (0);
}
