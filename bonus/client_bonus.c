/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:08:47 by dehamad           #+#    #+#             */
/*   Updated: 2024/04/04 01:28:34 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	ack_signal(int signum)
{
	if (signum == SIGUSR1)
	{
		write(1, "Message sent successfully\n", 26);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_atoi	res;
	pid_t	server_pid;
	pid_t	client_pid;

	client_pid = getpid();
	if (ac != 3)
		exit_error(AC_ERR);
	is_valid_arg(av[1]);
	res = ft_atoi(av[1]);
	if (res.error)
		exit_error(PID_ERR);
	server_pid = res.nbr;
	if (!server_pid)
		exit_error(KERNAL_ERR);
	if (!*av[2])
		return (0);
	signal(SIGUSR1, ack_signal);
	send_signals(server_pid, av[2]);
	return (0);
}
