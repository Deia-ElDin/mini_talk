/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:08:47 by dehamad           #+#    #+#             */
/*   Updated: 2024/04/01 09:44:07 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(pid_t pid, char c);

int	main(int ac, char **av)
{
	t_atoi	res;
	pid_t	pid;
	char	*str;

	if (ac != 3)
		return (0);
	res = ft_atoi(av[1]);
	if (res.error)
		return (0);
	pid = res.nbr;
	str = av[2];
	while (*av[2])
		(send_bit(pid, *av[2]), av[2]++);
	return (0);
}

void	send_bit(pid_t pid, char c)
{
	int	bit_index;

	bit_index = 8;
	while (bit_index)
	{
		if ((c >> --bit_index) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}
