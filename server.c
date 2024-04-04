/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:08:47 by dehamad           #+#    #+#             */
/*   Updated: 2024/04/04 09:00:07 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receive_signals(int signum)
{
	static char	bits[8];
	static int	index;
	int			decimal;
	int			i;

	if (index == 8)
		return ;
	if (signum == SIGUSR1)
		bits[index++] = '0';
	else if (signum == SIGUSR2)
		bits[index++] = '1';
	if (index == 8)
	{
		i = 0;
		decimal = 0;
		while (i < 8)
			decimal = (decimal << 1) | (bits[i++] - '0');
		ft_putchar_fd(decimal, 1);
		index = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, receive_signals);
	signal(SIGUSR2, receive_signals);
	while (1)
		pause();
	return (0);
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
