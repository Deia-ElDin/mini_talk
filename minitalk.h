/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:08:59 by dehamad           #+#    #+#             */
/*   Updated: 2024/04/01 10:27:46 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./libft/libft.h"
# include <signal.h>

void	send_bit(pid_t pid, char c);
void	sigusr_handler(int signum);
void	binary_to_decimal(const char *str);

#endif
