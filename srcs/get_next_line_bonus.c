/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:50:49 by tviejo            #+#    #+#             */
/*   Updated: 2024/04/10 09:50:40 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE] = {{0}};
	char		*tempbuffer;
	char		*output;
	char		nbbyte;

	if (fd < 0 || fd > 1024)
		return (NULL);
	if (buffer[fd][0] == '\0')
		if (read(fd, buffer[fd], BUFFER_SIZE) <= 0)
			return (NULL);
	nbbyte = get_first_line(buffer[fd]);
	output = malloc((nbbyte) * sizeof(char));
	if (output == NULL)
		return (NULL);
	ft_strncpy(output, buffer[fd], nbbyte, nbbyte + 1);
	tempbuffer = ft_remove_returned(buffer[fd], nbbyte);
	ft_strncpy(buffer[fd], tempbuffer, ft_strlen(tempbuffer), BUFFER_SIZE);
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
	printf("%d\n", fd);
	int fd2 = open("test2.txt", O_RDONLY | O_CREAT);
	printf("%d\n", fd2);
	int fd3 = open("test3.txt", O_RDONLY | O_CREAT);
	printf("%d\n\n", fd3);
        while (i < 20)
        {
		printf("\n\n%d\n", i);
		ultimate_str = get_next_line(fd);
                printf("\n%s", ultimate_str);
                free(ultimate_str);
		ultimate_str = get_next_line(fd2);
                printf("\n%s", ultimate_str);
                free(ultimate_str);
		ultimate_str = get_next_line(fd3);
                printf("\n%s", ultimate_str);
                free(ultimate_str);
		i++;
        }
        return (0);
}
*/
