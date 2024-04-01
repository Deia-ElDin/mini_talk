/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:08:47 by dehamad           #+#    #+#             */
/*   Updated: 2024/04/01 09:47:48 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigusr_handler(int signum);

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	signal(SIGUSR1, sigusr_handler);
	signal(SIGUSR2, sigusr_handler);
	while (1)
		pause();
	return (0);
}

void	sigusr_handler(int signum)
{
	static char	str[9];
	static int	index = 0;

	if (signum == SIGUSR1)
		str[index] = '0';
	else if (signum == SIGUSR2)
		str[index] = '1';
	index++;
	if (index == 8)
	{
		// printf("Received char: %c\n", strtol(str, NULL, 2));
		index = 0;
	}
}