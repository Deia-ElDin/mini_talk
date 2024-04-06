/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:08:47 by dehamad           #+#    #+#             */
/*   Updated: 2024/04/06 07:16:11 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receive_signals(int signum)
{
	static char	character;
	static int	index;

	character = character << 1;
	if (signum == SIGUSR1)
		character = character | 0;
	if (signum == SIGUSR2)
		character = character | 1;
	index++;
	if (index == 8)
	{
		index = 0;
		write(1, &character, 1);
		character = 0;
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
		initialize
			character: 00000000


		(00000000)₂ = (0 × 2⁷) + (0 × 2⁶) + (0 × 2⁵) + (0 × 2⁴) + (0 × 2³)
		+ (0 × 2²) + (0 × 2¹) + (0 × 2⁰) = (0)₁₀

		character = character << 1;
		if (signum == SIGUSR1)
			character = 00000000 | 00000000 = 00000000;
		if (signum == SIGUSR2)
			character = 00000000 | 00000001 = 00000001;

		character = character << 1;
		if (signum == SIGUSR1)
			character = 00000010 | 00000000 = 00000010;
		if (signum == SIGUSR2)
			character = 00000010 | 00000001 = 00000011;

		character = character << 1;
		if (signum == SIGUSR1)
			character = 00000110 | 00000000 = 00000110;
		if (signum == SIGUSR2)
			character = 00000110 | 00000001 = 00000111;
		
	}
*/
