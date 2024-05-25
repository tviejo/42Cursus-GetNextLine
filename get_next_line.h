/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:50:56 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/21 22:36:21 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strncpy(char *dest, char *scr, int n);
void	ft_remove_returned(char *buffer);
int		get_first_line(char *buffer);
void	*ft_bzero(void *s, size_t n);
int		ft_is_new_line(char *buffer);
char	*ft_remove_buffer(char *output);
char	*ft_read(char *buffer, int fd);
char	*ft_realloc(char *ptr, char *buffer, int n);

#endif
