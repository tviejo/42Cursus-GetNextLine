/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:50:27 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/19 19:42:14 by tviejo           ###   ########.fr       */
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
	while (i < n && scr[i] != '\0')
	{
		dest[i] = scr[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_remove_returned(char *buffer, int n)
{
	int		i;
	char	*newbuffer;

	newbuffer = malloc(BUFFER_SIZE * sizeof(char));
	if (newbuffer == NULL)
		return (newbuffer);
	i = n;
	while (buffer[i] != '\0')
	{
		newbuffer[i - n] = buffer[i];
		i++;
	}
	newbuffer[i - n] = '\0';
	return (newbuffer);
}

int	get_first_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		return (i + 1);
	else
		return (i);
}

int	ft_is_new_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
