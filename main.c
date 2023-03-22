/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharnec <jcharnec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:36:26 by jcharnec          #+#    #+#             */
/*   Updated: 2023/03/21 22:55:21 by jcharnec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int    main(void)
{
    int     fd;
    char    *line = malloc(1 * sizeof(char));

    fd = open("test.txt", BUFFER_SIZE);
    while(line != NULL)
    {
        free(line);
        line = get_next_line(fd);
        printf("%s", line);
    }
    return (0);
}