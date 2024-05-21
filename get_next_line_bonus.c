/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:50:49 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/21 23:02:36 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_realloc(char *ptr, char *buffer, int n)
{
	void	*temp;

	temp = malloc((ft_strlen(ptr) + 1) * sizeof(char));
	if (temp == NULL)
		return (temp);
	ft_strncpy(temp, ptr, ft_strlen(ptr) + 1);
	free(ptr);
	ptr = malloc((n + 1) * sizeof(char));
	if (ptr == NULL)
		return (ptr);
	ft_strncpy(ptr, temp, ft_strlen(temp) + 1);
	ft_strncpy(ptr + ft_strlen(temp), buffer, ft_strlen(buffer) + 1);
	free(temp);
	ptr[n] = '\0';
	return (ptr);
}

char	*ft_remove_buffer(char *output)
{
	int	i;

	i = 0;
	while (output[i] != '\0' && output[i] != '\n')
		i++;
	if (output[i] == '\n')
	{
		i++;
		while (output[i] != '\0')
		{
			output[i] = '\0';
			i++;
		}
	}
	return (output);
}

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
	return (s);
}

char	*ft_read(char *buffer, int fd)
{
	int		byte;
	int		byte_read;
	char	*output;

	byte_read = ft_strlen(buffer);
	byte = 1;
	output = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (output == NULL)
		return (output);
	ft_strncpy(output, buffer, BUFFER_SIZE + 1);
	while (ft_is_new_line(buffer) == 0 && byte > 0 && output != NULL)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
			return (ft_bzero(buffer, BUFFER_SIZE + 1), free(output), NULL);
		if (byte > 0)
		{
			buffer[byte] = '\0';
			byte_read += byte;
			output = ft_realloc(output, buffer, byte_read + 1);
		}
	}
	return (output);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1] = {{'\0'}};
	char		*output;

	output = ft_read(buffer[fd], fd);
	if (output == NULL)
		return (ft_bzero(buffer, BUFFER_SIZE + 1), output);
	ft_remove_returned(buffer[fd]);
	output = ft_remove_buffer(output);
	if (output[0] == '\0')
		return (ft_bzero(buffer[fd], BUFFER_SIZE + 1), free(output), NULL);
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
