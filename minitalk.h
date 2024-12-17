#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdint.h>
# include <signal.h>
# include <stdlib.h>
# include <limits.h>

extern sig_atomic_t	g_flag;

typedef struct s_minitalk
{
	uint8_t	c;
	uint8_t	bit_count;
}			t_minitalk;

void	error_exit(char *e);
void	send_sig(uint8_t c, pid_t pid);
void	set_signal(void);

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);

#endif
