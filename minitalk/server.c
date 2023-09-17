/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:56:14 by inhkim            #+#    #+#             */
/*   Updated: 2023/09/17 20:29:18 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

volatile t_buff	g_buf;

#include <stdlib.h>

void	leak_check(void)
{
	system("leaks server");
}
void	handler(int sig, siginfo_t *sip, void *none)
{
	(void)sip;
	(void)none;
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("OK", 2);
	}
}

static void	print_start(void)
{
	ft_putendl_fd("The server is running!", 1);
	ft_putstr_fd("Server PID is ", 1);
	ft_putnbr_fd((int)getpid(), 1);
	ft_putendl_fd("!", 1);
}

int	main(void)
{
	struct sigaction	sigact;

	atexit(leak_check);
	print_start();
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = &handler;
	sigemptyset(&sigact.sa_mask);
	sigaddset(&sigact.sa_mask, SIGUSR1);
	sigaddset(&sigact.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		;
	return (0);
}
