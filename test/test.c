/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:12:49 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/21 21:39:02 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int     main(void)
{
        char *ultimate_str;
        int     i;
        int     fd;

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
	close(fd);
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
	close(fd);
        printf("\n\nempty:\n");

        i = 0;
        fd = open("empty.txt", O_RDONLY | O_CREAT);
        while (i < 20)
        {
                ultimate_str = get_next_line(fd);
                printf("%s", ultimate_str);
                free(ultimate_str);
                i++;
        }
	close(fd);
        printf("\n\nbasic");

        i = 0;
        fd = open("test4.txt", O_RDONLY | O_CREAT);
        while (i < 20)
        {
                ultimate_str = get_next_line(fd);
                printf("%s", ultimate_str);
                free(ultimate_str);
                i++;
        }
	close(fd);
        printf("\n\nno_nl:\n");

        i = 0;
        fd = open("no_newline.txt", O_RDONLY | O_CREAT);
        while (i < 20)
        {
                ultimate_str = get_next_line(fd);
                printf("%s", ultimate_str);
                free(ultimate_str);
                i++;
        }
	close(fd);
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
	close(fd);
//        printf("\n\n\n");

//        i = 0;
//        fd = open("big_line_without_nl.txt", O_RDONLY | O_CREAT);
//        while (i < 1)
//        {
//                ultimate_str = get_next_line(fd);
//                printf("%s", ultimate_str);
//                free(ultimate_str);
//                i++;
//        }
//	close(fd);
        printf("\n\n41 with nl:\n");

        i = 0;
        fd = open("41_with_nl", O_RDONLY | O_CREAT);
        while (i < 20)
        {
                ultimate_str = get_next_line(fd);
                printf("%s", ultimate_str);
                free(ultimate_str);
                i++;
        }
	close(fd);
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
	close(fd);
	printf("\n\n43 with nl:\n");

        i = 0;
        fd = open("43_with_nl", O_RDONLY | O_CREAT);
        while (i < 20)
        {
                ultimate_str = get_next_line(fd);
                printf("%s", ultimate_str);
                free(ultimate_str);
                i++;
        }
	close(fd);
	printf("\n\nmultiple_nlx5:\n");

        i = 0;
        fd = open("multiple_nlx5", O_RDONLY | O_CREAT);
        while (i < 20)
        {
                ultimate_str = get_next_line(fd);
                printf("%s", ultimate_str);
                free(ultimate_str);
                i++;
        }
	close(fd);
	printf("\n\none_line_no_nl:\n");

        i = 0;
        fd = open("test5.txt", O_RDONLY | O_CREAT);
        while (i < 3)
        {
                ultimate_str = get_next_line(fd);
                printf("%s", ultimate_str);
                free(ultimate_str);
                i++;
        }
	close(fd);

//	printf("\n\nalternate_line:\n");
//
//        i = 0;
//        fd = open("alternate_line_nl_no_nl", O_RDONLY | O_CREAT);
//        while (i < 20)
//        {
//                ultimate_str = get_next_line(fd);
//                printf("%s", ultimate_str);
//                free(ultimate_str);
//                i++;
//        }
//	close(fd);

//        printf("\n\nstdin:\n");

//      i = 0;
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
