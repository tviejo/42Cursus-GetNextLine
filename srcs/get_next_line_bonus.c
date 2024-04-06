/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:50:49 by tviejo            #+#    #+#             */
/*   Updated: 2024/04/06 16:14:51 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list  *ft_lstcreate(int fd)
{
        t_list  *list;

        list = (t_list *)malloc(sizeof(t_list));
        if (list == NULL)
                return (list);
        list->fd = fd;
	list->buffer[0] = '\0';
	list->prev = NULL;
        list->next = NULL;
        return (list);
}

t_list *ft_lstadd(int fd, t_list *list)
{
	t_list	*listoutput;

        listoutput = (t_list *)malloc(sizeof(t_list));
        if (listoutput == NULL)
                return (listoutput);
        listoutput->fd = fd;
        listoutput->buffer[0] = '\0';
        listoutput->prev = list;
	printf("test%d", list->fd);
        listoutput->next = NULL;
        return (listoutput);
}

t_list	*find_correct_list(int	fd, t_list *list)
{
	t_list	*temp_list;

	if (list == NULL)
		return (ft_lstcreate(fd));
	else
	{
		printf("bef:%d",list->fd);
		while (list->prev != NULL)
		{
			list = list->prev;
			printf("aft:%d",list->fd);
		}
		while (list != NULL)
		{
			if (list->fd == fd)
				return (list);
			temp_list = list;
			list = list->next;
		}
	}
	return (ft_lstadd(fd, temp_list));
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char		*tempbuffer;
	char		*output;
	char		nbbyte;

	list = find_correct_list(fd, list);
	if (list->buffer[0] == '\0')
		if (read(list->fd, list->buffer, BUFFER_SIZE) <= 0)
			return (NULL);
	nbbyte = get_first_line(list->buffer);
	output = malloc((nbbyte) * sizeof(char));
	if (output == NULL)
		return (NULL);
	ft_strncpy(output, list->buffer, nbbyte, nbbyte + 1);
	tempbuffer = ft_remove_returned(list->buffer, nbbyte);
	ft_strncpy(list->buffer, tempbuffer, ft_strlen(tempbuffer), ft_strlen(list->buffer));
	free(tempbuffer);
	return (output);
}

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
