#include <signal.h>
#include <unistd.h>
#include "./minitalk.h"

t_buff	g_buf;

void	handler(int sig, siginfo_t *sip, ucontext_t *ucp)
{
    (void)ucp;
    if (sig == SIGUSR1)
    {
        
    }
    
}

static void	print_start()
{
	ft_printf("The server is running!")
	ft_printf("Server PID is %d\n", (int)getpid());
}

int	main(void)
{
    struct sigaction	sigact;
    
	print_start();
    sigact.sa_flags = SA_SIGINFO;
    sigact.sa_sigaction = &handler;
	if (sigemptyset(&sig.sa_mask))
		return (1);
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);	
	while (1)
		;
	return(0); 
}