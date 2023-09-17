/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:56:14 by inhkim            #+#    #+#             */
/*   Updated: 2023/09/17 17:33:23 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "./minitalk.h"

t_buff	g_buf;

#include <stdlib.h>

void	leak_check(void)
{
	system("leaks server");
}
void	handler(int sig, siginfo_t *sip, void *none)
{
	(void)sip;
	(void)none;
	if (sig == SIGINT)
	{
		ft_printf("OK");
	}
}

static void	print_start(void)
{
	ft_printf("The server is running!\n");
	ft_printf("Server PID is %d\n", (int)getpid());
}

int	main(void)
{
	struct sigaction	sigact;

	atexit(leak_check);
	print_start();
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = &handler;
	if (sigemptyset(&sigact.sa_mask))
		return (1);
	sigaddset(&sigact.sa_mask, SIGUSR1);
	sigaddset(&sigact.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		;
	return (0);
}
