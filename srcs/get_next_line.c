/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:50:49 by tviejo            #+#    #+#             */
/*   Updated: 2024/04/05 23:21:16 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_first_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		return (i + 1);
	else
		return (i);
}

char    *get_next_line(int fd)
{
	static char    buffer[BUFFER_SIZE] = "\0";
	char	*newbuffer;
	char	*output;
	char	nbbyte;

	if (buffer[0] == '\0')
	{
//		printf("read");
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
			return (NULL);
	}
	nbbyte = get_first_line(buffer);
	output = malloc((nbbyte + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	output = ft_strncpy(output, buffer, nbbyte);
//	printf("\ntest0: %s\n", output);
	newbuffer = ft_remove_returned(buffer, nbbyte);
//	printf("\ntest1: %s\n", newbuffer);
	ft_strncpy(buffer, newbuffer, BUFFER_SIZE);
	free(newbuffer);
	return (output);
}

int     main(void)
{
        char *ultimate_str;
	int	i;

	i = 0;
	int fd = open("test.txt", O_RDONLY | O_CREAT);
        while (i < 10)
        {
                ultimate_str = get_next_line(fd);
                printf("%s",ultimate_str);
                free(ultimate_str);
		i++;
        }
        return (0);
}
