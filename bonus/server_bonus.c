/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:08:47 by dehamad           #+#    #+#             */
/*   Updated: 2024/04/08 05:03:44 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	receive_signals_bonus(int signum, siginfo_t *info, void *context)
{
	pid_t		client_pid;
	static char	character;
	static int	index;

	(void)context;
	character = character << 1;
	if (signum == SIGUSR1)
		character = character | 0;
	if (signum == SIGUSR2)
		character = character | 1;
	index++;
	if (index == 8)
	{
		write(1, &character, 1);
		client_pid = info->si_pid;
		if (!character)
			kill(client_pid, SIGUSR1);
		index = 0;
		character = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sa.sa_sigaction = receive_signals_bonus;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

/*
	struct sigaction {
		void (*sa_handler)(int);
		void (*sa_sigaction)(int, siginfo_t *, void *);
		sigset_t sa_mask;
		int sa_flags;
		void (*sa_restorer)(void);
	};

	sigaction:
	change the action taken by a process on receipt of a specific signal.
	It allows you to specify a handler function to be called when the 
	signal occurs, among other options. 
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

	sigemptyset: This is a function that initializes a signal set 
	to be empty, meaning it clears all signals from the set.

	SA_SIGINFO is a flag used in the sa_flags field of the struct 
	sigaction structure in Unix-like operating systems, including 
	Linux. It indicates that the signal handler function 
	(sa_sigaction) expects to receive additional information 
	about the signal when it is called.

	static void	receive_signals_bonus(int signum, siginfo_t *info, void *context)
	{
		void *context is included to match the function signature required 
		by the sa_sigaction field of the struct sigaction structure. 
		When using sa_sigaction to specify a signal handler, the function 
		signature must match a specific format:
		void handler_function(int signum, siginfo_t *info, void *context)

		The context parameter is not always used in signal handling, but it's 
		provided to offer additional information or context related 
		to the signal.
	}	
*/
