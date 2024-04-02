/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:08:59 by dehamad           #+#    #+#             */
/*   Updated: 2024/04/03 01:57:57 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./libft/libft.h"
# include <signal.h>

# define AC_ERR "Invalid number of arguments"
# define PID_ERR "Invalid PID"
# define KERNAL_ERR "Invalid PID, kernal process can't be used"

// Utils
void	exit_error(char *str);
void	is_valid_arg(char *str);
void	send_signals(pid_t pid, char *str);
void	receive_signals(int signum);

#endif
