/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:08:47 by dehamad           #+#    #+#             */
/*   Updated: 2024/04/03 03:32:23 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	sig_handler(int signum, siginfo_t *info, void *context)
{
	pid_t		client_pid;
	static char	bits[9];
	static int	index;
	int			decimal;
	int			i;

	(void)context;
	if (signum == SIGUSR1)
		bits[index++] = '0';
	else if (signum == SIGUSR2)
		bits[index++] = '1';
	decimal = 0;
	i = 0;
	if (index == 8)
	{
		while (i < 8)
			decimal = (decimal << 1) | (bits[i++] - '0');
		ft_putchar_fd(decimal, 1);
		index = 0;
		client_pid = info->si_pid;
		if (!decimal)
			kill(client_pid, SIGUSR1);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sa.sa_sigaction = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
