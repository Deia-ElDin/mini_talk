/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:08:47 by dehamad           #+#    #+#             */
/*   Updated: 2024/04/06 07:02:03 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	exit_error(char *str)
{
	ft_printf(2, "%s\n", str);
	exit(EXIT_FAILURE);
}

static void	is_valid_arg(char *str)
{
	int	i;
	int	dash_counter;

	if (!*str)
		exit_error(PID_ERR);
	i = 0;
	dash_counter = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || (str[i] == '-' && ++dash_counter)))
			exit_error(PID_ERR);
		if (dash_counter > 1)
			exit_error(PID_ERR);
		i++;
	}
}

static void	send_signals(pid_t pid, char *str)
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
				exit_error(PID_ERR);
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

int	main(int ac, char **av)
{
	t_atoi	res;
	pid_t	pid;

	if (ac != 3)
		exit_error(AC_ERR);
	is_valid_arg(av[1]);
	res = ft_atoi(av[1]);
	if (res.error)
		exit_error(PID_ERR);
	pid = res.nbr;
	if (!pid)
		exit_error(SAME_PROCCESS_ERR);
	if (pid == -1)
		exit_error(PID_ERR);
	send_signals(pid, av[2]);
	return (0);
}

/*
	if ((*str >> --bit_index) & 1)
	assume: *str = 001100101
		*str >> --bit_index = 001100101 >> 7 = 00000000
		00000000 & 00000001 = 00000000
	
*/