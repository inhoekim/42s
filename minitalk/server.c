/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:56:14 by inhkim            #+#    #+#             */
/*   Updated: 2023/10/08 14:11:58 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

volatile t_buff	g_buf;

void	recieve_handler(int sig, \
struct __siginfo *sif, void *none)
{
	(void) none;
	if (sig == SIGUSR1)
		g_buf.buf |= (1 << g_buf.offset);
	g_buf.offset++;
	kill(sif->si_pid, SIGUSR1);
	if (g_buf.offset == 8)
	{
		ft_putstr_fd((char *)&g_buf.buf, 1);
		g_buf.buf = 0;
		g_buf.offset = 0;
		return ;
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

	print_start();
	sigact.sa_sigaction = &recieve_handler;
	sigemptyset(&sigact.sa_mask);
	sigaddset(&sigact.sa_mask, SIGUSR1);
	sigaddset(&sigact.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	g_buf.offset = 0;
	g_buf.buf = 0;
	while (1)
		;
	return (0);
}
