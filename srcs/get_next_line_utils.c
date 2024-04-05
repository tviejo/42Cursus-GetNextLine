/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:50:27 by tviejo            #+#    #+#             */
/*   Updated: 2024/04/05 23:20:47 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strncpy(char *dest, char *scr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = scr[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char    *ft_remove_returned(char *buffer, int n)
{
	int	i;
	char	*newbuffer;

	newbuffer = malloc(BUFFER_SIZE * sizeof(char));
	i = n;
	while (buffer[i] != '\0')
	{
		newbuffer[i - n] = buffer[i];
		i++;
	}
	while (i < BUFFER_SIZE + n)
	{
		newbuffer[i - n] = '\0';
		i++;
	}
	return (newbuffer);
}
