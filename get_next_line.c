/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:50:49 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/19 19:41:07 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	*ft_realloc(void *ptr, char *buffer, int n)
{
	void	*temp;
	
	temp = malloc((ft_strlen(ptr) + 1) * sizeof(char));
	if (temp == NULL)
		return (temp);
	ft_strncpy(temp, ptr, ft_strlen(ptr));
	free(ptr);
	ptr = malloc((n + 1) * sizeof(char));
	if (ptr == NULL)
		return (ptr);
	ft_strncpy(ptr, temp, ft_strlen(temp));
	ft_strncpy(ptr + ft_strlen(temp), buffer, ft_strlen(buffer));
	free(temp);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = "\0";
	char		*output;
	char		*tempbuffer;
	int		byte_read;
	int		byte;

	byte_read = 0;
	byte = 1;
	if (fd < 0 || fd > 1023)
		return (NULL);
	output = malloc(1 * sizeof(char));
	if (output == NULL)
		return (output);
	output[0] = '\0';
	while (ft_is_new_line(buffer) == 0 && byte > 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		buffer[byte] = '\0';
		byte_read += byte;
		output = ft_realloc(output, buffer, byte_read + 1);
	}
	if (byte_read < 1)
		return (NULL);
	tempbuffer = ft_remove_returned(buffer, byte);
	ft_strncpy(buffer, tempbuffer, ft_strlen(tempbuffer) + 1);
	free(tempbuffer);
	return (output);
}

int     main(void)
{
        char *ultimate_str;
	int	i;
	int	fd;

	printf("basic:\n");
	i = 0;
        fd = open("test2.txt", O_RDONLY | O_CREAT);
        while (i < 20)
        {
                ultimate_str = get_next_line(fd);
                printf("%s", ultimate_str);
                free(ultimate_str);
                i++;
        }
        printf("\n\nbasic without nl:\n");

	i = 0;
        fd = open("test3.txt", O_RDONLY | O_CREAT);
        while (i < 20)
        {
                ultimate_str = get_next_line(fd);
                printf("%s", ultimate_str);
                free(ultimate_str);
                i++;
        }
        printf("\n\n");	

	i = 0;
	fd = open("test4.txt", O_RDONLY | O_CREAT);
        while (i < 20)
        {
                ultimate_str = get_next_line(fd);                
		printf("%s", ultimate_str);
		free(ultimate_str);
		i++;
        }
	printf("\n\n:no_nl:\n");

	i = 0;
	fd = open("no_newline.txt", O_RDONLY | O_CREAT);
        while (i < 20)
        {
                ultimate_str = get_next_line(fd);
                printf("%s", ultimate_str);
                free(ultimate_str);
                i++;
        }
	printf("\n\nbig line with nl:\n");

	i = 0;
	fd = open("big_line_with_nl.txt", O_RDONLY | O_CREAT);
        while (i < 20)
        {
                ultimate_str = get_next_line(fd);
                printf("%s", ultimate_str);
                free(ultimate_str);
                i++;
        }
	printf("\n\nsize buffer:\n");

        i = 0;
        fd = open("big_line_without_nl.txt", O_RDONLY | O_CREAT);
        while (i < 1)
        {
                ultimate_str = get_next_line(fd);
                printf("%s", ultimate_str);
                free(ultimate_str);
                i++;
        }
        printf("\n\nbig line without nl:\n");

	i = 0;
        fd = open("big_line_without_nl.txt", O_RDONLY | O_CREAT);
        while (i < 20)
        {
                ultimate_str = get_next_line(fd);
                printf("%s", ultimate_str);
                free(ultimate_str);
                i++;
        }
//        printf("\n\nstdin:\n");
	
//	i = 0;
//        fd = 0;
//        while (i < 20)
//        {
//                ultimate_str = get_next_line(fd);
//                printf("%s", ultimate_str);
//                free(ultimate_str);
//                i++;
//        }
//        printf("\n\n");
}
