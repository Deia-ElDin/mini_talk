/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tobinary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 04:12:43 by dehamad           #+#    #+#             */
/*   Updated: 2024/04/01 08:53:15 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to.h"

char	*ft_tobinary(char *str)
{
	char	*bits;
	size_t	len;
	int		bit_index;
	size_t	index;

	len = ft_strlen(str);
	if (!len)
		return (NULL);
	bits = (char *)ft_calloc(len * 8 + 1, sizeof(char));
	if (!bits)
		return (NULL);
	index = 0;
	while (*str)
	{
		bit_index = 8;
		while (bit_index)
			bits[index++] = ((*str >> --bit_index) & 1) + '0';
		str++;
	}
	return (bits);
}
