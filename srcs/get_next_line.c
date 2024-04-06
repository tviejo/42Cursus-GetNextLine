/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:50:49 by tviejo            #+#    #+#             */
/*   Updated: 2024/04/06 11:39:35 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE] = "\0";
	char		*tempbuffer;
	char		*output;
	char		nbbyte;

	if (buffer[0] == '\0')
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
			return (NULL);
	nbbyte = get_first_line(buffer);
	output = malloc((nbbyte) * sizeof(char));
	if (output == NULL)
		return (NULL);
	ft_strncpy(output, buffer, nbbyte, nbbyte + 1);
	tempbuffer = ft_remove_returned(buffer, nbbyte);
	ft_strncpy(buffer, tempbuffer, ft_strlen(tempbuffer), ft_strlen(buffer));
	free(tempbuffer);
	return (output);
}
/*
int     main(void)
{
        char *ultimate_str;
	int	i;

	i = 0;
	int fd = open("test.txt", O_RDONLY | O_CREAT);
        while (i < 20)
        {
                ultimate_str = get_next_line(fd);
                printf("%s", ultimate_str);
		free(ultimate_str);
		i++;
        }
        return (0);
}
*/
