/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:08:47 by dehamad           #+#    #+#             */
/*   Updated: 2024/04/04 05:22:17 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	sig_handler(int signum, siginfo_t *info, void *context)
{
	pid_t		client_pid;
	static char	bits[8];
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

/*
	sigaction:
	The sigaction function is used in Unix-like operating systems 
	(including Linux) to change the action taken by a process on 
	receipt of a specific signal. It allows you to specify a handler 
	function to be called when the signal occurs, among other options. 
	Here's a breakdown of its parameters:
	1) signum: The signal number you want to change the action for.
	2) sa: A pointer to a struct sigaction object containing information
		about the action to be taken.
	3) oldact: (Optional) A pointer to a struct sigaction object where 
		the previous action for the signal will be stored.

	The struct sigaction object (sa) contains the following members:
	1) sa_handler: A pointer to the signal handling function. 
		Either this or sa_sigaction should be set, but not both.
	2) sa_sigaction: A pointer to the signal handling function with 
		an extended signature that includes additional information 
		about the signal and the context in which it occurred.
	3) sa_mask: A set of signals to be blocked while the signal 
		handler is executing. This prevents the handler from being 
		interrupted by certain signals.
	4) sa_flags: Additional flags that modify the behavior of the signal 
		handler. These can include options like SA_RESTART, 
		SA_SIGINFO, and others.
*/
