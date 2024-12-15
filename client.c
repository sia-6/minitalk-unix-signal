#include "minitalk.h"

sig_atomic_t	g_flag;

static void	wait_signal(uint64_t word_count, uint8_t c)
{
	while (!g_flag)
		;
	if (!(c == 0 && g_flag > 0) && !(c == 1 && g_flag < 0))
		error_exit("Signal error");
	g_flag = 0;
	if (word_count >= 10000)
		usleep(30);
	else if (word_count >= 1000)
		usleep(20);
	usleep(30);
}

static void	send_msg(char *msg, pid_t server_pid)
{
	uint8_t		c;
	uint8_t		bit;
	uint64_t	word_count;

	word_count = 0;
	while (*msg)
	{
		c = (uint8_t)(*msg++);
		bit = -1;
		while (++bit < 8)
		{
			send_sig(c, server_pid);
			wait_signal(word_count, c & 1);
			c >>= 1;
		}
		word_count++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
		error_exit("Invalid argument");
	server_pid = (pid_t)ft_atoi(argv[1]);
	if (server_pid == 0 || server_pid == -1)
		error_exit("Inappropriate proccess");
	if (kill(server_pid, 0) == -1)
		error_exit("No such proccess");
	set_signal();
	g_flag = 0;
	send_msg(argv[2], server_pid);
}
