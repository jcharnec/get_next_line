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

// Se libera la memoria del puntero asignada con malloc y lo pone a NULL.
void	free_ptr(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		ptr = NULL;
	}
}

char	*join_line(int nl_position, char **buffer)
{
	char	*res;
	char	*tmp;

	tmp = NULL;
	if (nl_position <= 0 )
	{
		if (**buffer == '\0')
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		res = *buffer;
		*buffer = NULL;
		return (res);
	}
	tmp = ft_substr(*buffer, nl_position, BUFFER_SIZE);
	res = *buffer;
	res[nl_position] = 0;
	*buffer = tmp;
	return (res);
}

char	*read_line(int fd, char **buffer, char *read_return)
{
	ssize_t	bytes_read;
	char	*tmp;
	char	*nl;

	nl = ft_strchr(*buffer, '\n');
	tmp = NULL;
	bytes_read = 0;
	while (nl == NULL)
	{
		bytes_read = read(fd, read_return, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (join_line(bytes_read, buffer));
		read_return[bytes_read] = 0;
		tmp = ft_strjoin(*buffer, read_return);
		free_ptr(buffer);
		*buffer = tmp;
		nl = ft_strchr(*buffer, '\n');
	}
	return (join_line(nl - *buffer + 1, buffer));
}

// Esta función lee una línea de un archivo o de stdin usando un tamaño de 
// búfer definido por una macro BUFFER_SIZE.
char *get_next_line(int fd)
{
    // Se declara un array estatico com buffer. Se usa para guardar el contenido 
    // del archivo que se lee entre llamadas a la funcion. 
    // El tamaño del array es MAX_FD + 1, que es una constante que define el numero 
    // máximo de fd posibles.
    static char *buffer[MAX_FD + 1];
    // Variable para guardar el resultado de la funcion read que lee  del archivo o stdin.
    char        *read_resu;
    // Variable para guardar la línea final que se va a devolver al final de la funcion.
    char        *final;
    // Comprueba si el file descriptor es valido.
    if (fd < 0 || BUFFER_SIZE <= 0 || fd < MAX_FD)
        return (NULL);
    // Reservamos memoria para la variable assignando el espacio demandado en BUFFER_SIZE + 1
    // para guardar el caracter \0.
    read_resu = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (read_resu == NULL)
        return (NULL);
    // Se comprueba si el buffer del file descriptor está vacío. Si lo está, lo inicializa 
    // con una cadena vacía con ft_strdup, que es una función 
    // auxiliar que duplica una cadena y reserva memoria para ella.
    if (!buffer[fd])
        buffer[fd] = ft_strdup("");
    // Llama a la función read_line que recibe como argumentos el fd, un puntero al elemento del array buffer correspondiente al fd y la variable read_return. Esta función se encarga de leer del archivo o stdin hasta encontrar un carácter ‘\n’ o llegar al final del archivo y devolver la línea leída sin el ‘\n’. También actualiza el contenido del array buffer con lo que queda por leer después del ‘\n’.
    final = read_line(fd, &buffer[fd], read_resu);
    free_ptr(&read_resu);
    return(final);
}