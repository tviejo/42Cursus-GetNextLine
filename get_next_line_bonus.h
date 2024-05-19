/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:50:56 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/19 17:42:51 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

int		ft_strlen(char *str);
char	*ft_strncpy(char *dest, char *scr, int n);
char	*ft_remove_returned(char *buffer, int n);
int		get_first_line(char *buffer);
char	*get_next_line(int fd);

#endif
