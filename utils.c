/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:26:31 by dehamad           #+#    #+#             */
/*   Updated: 2024/04/01 12:43:53 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	sigusr_handler(int signum)
{
	static char	bits[9];
	static int	index;

	if (signum == SIGUSR1)
		bits[index++] = '0';
	else if (signum == SIGUSR2)
		bits[index++] = '1';
	if (index == 8)
	{
		binary_to_decimal(bits);
		index = 0;
	}
}

void	binary_to_decimal(const char *bits)
{
	int	decimal;

	decimal = 0;
	while (*bits)
		decimal = (decimal * 2) + (*bits++ - '0');
	ft_putchar_fd(decimal, 1);
	if (decimal == '\n')
		signal(SIGUSR2, sigusr_handler);
}
