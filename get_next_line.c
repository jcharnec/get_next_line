/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharnec <jcharnec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:35:18 by jcharnec          #+#    #+#             */
/*   Updated: 2023/03/22 12:20:06 by jcharnec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Esta función lee una línea de un archivo o de stdin usando un tamaño de 
// búfer definido por una macro BUFFER_SIZE.
void *get_next_line (const int fd)
{
    // Se declara una variable estatica llamada buffer que es 
    // un array de punteros a char. Esta variable se usa para guardar el contenido 
    // del archivo que se lee entre llamadas a la funcion. 
    // El tamaño del array es MAX_FD + 1, que es una constante que define el numero 
    // máximo de file descriptors posibles.
    static char *buffer[MAX_FD + 1];
    // Variable para guardar el resultado de la funcion read que lee  del archivo o stdin.
    char        *line;
    // Variable para guardar la línea final que se va a devolver al final de la funcion.
    char        *final;
    // Comprueba si el file descriptor es valido.
    if (fd < 0 || BUFFER_SIZE <= 0 || fd < MAX_FD)
        return (NULL);
    // Reservamos memoria para la variable assignando el espacio demandado en BUFFER_SIZE + 1
    // para guardar el caracter \0.
    line = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (line == NULL)
        return (NULL);
    // Se comprueba si el buffer del file descriptor está vacío. Si lo está, lo inicializa 
    // con una cadena vacía con ft_strdup, que es una función 
    // auxiliar que duplica una cadena y reserva memoria para ella.
    if (!buffer[fd])
        buffer[fd] = ft_strdup("");
    // Llama a la función read_line que recibe como argumentos el fd, un puntero al elemento del array buffer correspondiente al fd y la variable read_return. Esta función se encarga de leer del archivo o stdin hasta encontrar un carácter ‘\n’ o llegar al final del archivo y devolver la línea leída sin el ‘\n’. También actualiza el contenido del array buffer con lo que queda por leer después del ‘\n’.
    final = read_line(fd, &buffer[fd], read_return);
    // función auxiliar llamada free_null que recibe como argumento un puntero al puntero read_return y libera su memoria asignada con malloc y lo pone a NULL.
    free_line(&read_return);
    return(final);
}