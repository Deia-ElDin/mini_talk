/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:08:47 by dehamad           #+#    #+#             */
/*   Updated: 2024/04/01 11:48:16 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	t_atoi	res;
	pid_t	pid;

	if (ac != 3)
		return (0);
	res = ft_atoi(av[1]);
	if (res.error)
		return (0);
	pid = res.nbr;
	while (*av[2])
	{
		send_bit(pid, *av[2]);
		av[2]++;
	}
	send_bit(pid, '\n');
	return (0);
}
