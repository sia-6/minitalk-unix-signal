#include "minitalk.h"

void	error_exit(char *e)
{
	ft_putendl_fd(e, 2);
	exit(EXIT_FAILURE);
}

void	send_sig(uint8_t c, pid_t pid)
{
	if (!(c & 1))
	{
		if (kill(pid, SIGUSR1) == -1)
			error_exit("kill error : SIGUSR1");
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			error_exit("kill error : SIGUSR2");
	}
}

static void	signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (sig == SIGUSR1)
		g_flag = info->si_pid;
	else if (sig == SIGUSR2)
		g_flag = -info->si_pid;
}

void	set_signal(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &signal_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		error_exit("sigaction error : SIGUSR1");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		error_exit("sigaction error : SIGUSR2");
}
