/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharnec <jcharnec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:03:41 by jcharnec          #+#    #+#             */
/*   Updated: 2023/03/24 14:12:41 by jcharnec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int main(void)
{
    int fd[3];
    char *line;
    int i;

    // Abrir los archivos de lectura
    fd[0] = open("text1.txt", O_RDONLY);
    fd[1] = open("text2.txt", O_RDONLY);
    fd[2] = open("text3.txt", O_RDONLY);

    // Leer una línea de cada archivo de forma alterna
    while (1)
    {
        for (i = 0; i < 3; i++)
        {
            line = get_next_line(fd[i]);
            if (line == NULL)
                break;
            printf("Linea leida del fd %d: %s", i + 1, line);
            free(line);
        }
		printf ("\n");
        if (line == NULL) // Salir del bucle si se ha terminado algun archivo o ha habido un error
            break;
    }

    // Cerrar los archivos
    for (i = 0; i < 3; i++)
        close(fd[i]);

    return (0);
}
