/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:08:47 by dehamad           #+#    #+#             */
/*   Updated: 2024/04/08 03:06:04 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	exit_error_bonus(char *str)
{
	ft_printf(2, "%s\n", str);
	exit(EXIT_FAILURE);
}

static void	is_valid_pid_bonus(char *str)
{
	int	i;
	int	dash_counter;

	if (!*str)
		exit_error_bonus(PID_ERR);
	i = 0;
	dash_counter = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || (str[i] == '-' && ++dash_counter)))
			exit_error_bonus(PID_ERR);
		if (dash_counter > 1)
			exit_error_bonus(PID_ERR);
		i++;
	}
}

static void	send_signals_bonus(pid_t pid, char *str)
{
	int	signal;
	int	bit_index;

	while (*str)
	{
		bit_index = 8;
		while (bit_index)
		{
			if ((*str >> --bit_index) & 1)
				signal = SIGUSR2;
			else
				signal = SIGUSR1;
			if (kill(pid, signal) == -1)
				exit_error_bonus(PID_ERR);
			usleep(300);
		}
		str++;
		if (!*str)
		{
			bit_index = 8;
			while (bit_index--)
				(kill(pid, SIGUSR1), usleep(300));
		}
	}
}

static void	ack_signal_bonus(int signum)
{
	if (signum == SIGUSR1)
		write(1, "Message sent successfully\n", 26);
}

int	main(int ac, char **av)
{
	t_atoi	res;
	pid_t	server_pid;

	if (ac != 3)
		exit_error_bonus(AC_ERR);
	is_valid_pid_bonus(av[1]);
	res = ft_atoi(av[1]);
	if (res.error)
		exit_error_bonus(PID_ERR);
	server_pid = res.nbr;
	if (!server_pid)
		exit_error_bonus(SAME_PROCCESS_ERR);
	if (server_pid == -1)
		exit_error_bonus(PID_ERR);
	if (!*av[2])
		return (0);
	signal(SIGUSR1, ack_signal_bonus);
	send_signals_bonus(server_pid, av[2]);
	return (0);
}
