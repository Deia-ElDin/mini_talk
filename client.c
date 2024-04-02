/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:08:47 by dehamad           #+#    #+#             */
/*   Updated: 2024/04/03 01:52:43 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		exit_error(KERNAL_ERR);
	send_signals(pid, av[2]);
	return (0);
}
