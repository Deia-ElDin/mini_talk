/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:26:31 by dehamad           #+#    #+#             */
/*   Updated: 2024/04/04 05:16:56 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	exit_error(char *str)
{
	ft_printf(2, "%s\n", str);
	exit(EXIT_FAILURE);
}

void	is_valid_arg(char *str)
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

void	send_signals(pid_t pid, char *str)
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
			usleep(200);
		}
		str++;
		if (!*str)
		{
			bit_index = 8;
			while (bit_index--)
				(kill(pid, SIGUSR1), usleep(200));
		}
	}
}

void	receive_signals(int signum)
{
	static char	bits[9];
	static int	index;
	int			decimal;
	int			i;

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
	}
}

/*
* void	receive_signals(int signum)
{

	while (i < 8)
		decimal = (decimal << 1) | (bits[i++] - '0');
		shifting decimal by 1 to the left == multiplying decimal by 2
		
	assume 
		bits: 01100100

	initialize
		decimal: 00000000

	bits[0]: 0
	decimal = (00000000 << 1 = 00000000 (0) | (0) 00000000) = (0) 00000000
	(00000000)₂ = (0 × 2⁷) + (0 × 2⁶) + (0 × 2⁵) + (0 × 2⁴) + (0 × 2³)
	+ (0 × 2²) + (0 × 2¹) + (0 × 2⁰) = (0)₁₀

	bits[1]: 1
	decimal = (00000000 << 1 = 00000000 (0) | (1) 00000001) = 00000001 = (1)

	bits[2]: 1
	decimal = (00000001 << 1 = 00000010 (2) | (1) 00000001) = 00000011 = (3)

	bits[3]: 0
	decimal = (00000011 << 1 = 00000110 (6) | (0) 00000000) = 00000110 = (6)

	bits[4]: 0
	decimal = (00000110 << 1 = 00001100 (12) | (0) 00000000) = 00001100 = (12)

	bits[5]: 1
	decimal = (00001100 << 1 = 00011000 (24) | (1) 00000001) = 00011001 = (25)

	bits[6]: 0
	decimal = (00011001 << 1 = 00110010 (50) | (0) 00000000) = 00110010 = (50)

	bits[7]: 0
	decimal = (00110010 << 1 = 01100100 (100) | (0) 00000000) = 01100100 = (100)
}
*/
