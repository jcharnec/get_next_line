/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharnec <jcharnec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:35:18 by jcharnec          #+#    #+#             */
/*   Updated: 2023/03/22 18:55:39 by jcharnec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Funcion para obtener parte de una cadena antes del '\n', 
// declaro dos variables,  i para contar el numero de caracteres 
// en cadena str, y ptr para guardar parte de la cadena antes
// del '\n' o del fina de cadena '\0'
char	*ft_first_line(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[0] == '\0')
	{
		return (NULL);
	}
	ptr = malloc(sizeof(char) * i + 2);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		ptr[i++] = '\n';
	ptr[i] = '\0';
	return (ptr);
}

// Funcion para obtener la cadena despues de '\n', Declaramos 3 variables, 
// i para contar el numero de caracteres j para buscar el primer '\n' y ptr 
// para guardar el contenido despues de '\n'
char	*ft_after(char *str)
{
	int		i;
	int		j;
	char	*ptr;

	j = 0;
	if (str == NULL)
		return (NULL);
	while (str[j] != '\n' && str[j] != '\0')
		j++;

	if (str[j] == '\0')
	{
		free(str);
		return (NULL);
	}
	ptr = malloc(sizeof(char) * ft_strlen(str) + 2);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j += 1;
	while (str[j] != '\0')
		ptr[i++] = str[j++];
	ptr[i] = '\0';
	free(str);
	return (ptr);
}

// Funcion que sirve para encontrar el final de linea,
// si str == '\n'.
int	ft_newline(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// Funcion que sirve para leer el archivo
char	*ft_read(int fd, char *buffer, char *tmp, char *str)
{
	int		i;
	// Inicializamos i en 1 para cotrolar el bucle de lectura.
	i = 1;
	// Mientras i no sea 0 no se ha llegado al final del archivo
	// o no ha ocurrido un error.
	while (i != 0)
	{
		// Guardamos en i el numero de bytes del descriptor i controlamos
		// que no hay ningun error, si es asi liberamos el buffer.
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free (buffer);
			return (NULL);
		}
		// Assignamos '\0' al final de buffer y guardamos str en tmp.
		buffer[i] = '\0';
		tmp = str;
		// Si tmp es NULL es la primera vez que leemos el archivo y le
		// asignamos memoria para 1 caracter y lo inicializamos.
		if (tmp == NULL)
		{
			tmp = malloc(sizeof(char) * 1);
			tmp[0] = '\0';
		}
		// Concatenamos tmp y buffer y liberamos tmp.
		str = ft_strjoin(tmp, buffer);
		free(tmp);
		// Llamamos la funcion ft_newline para comprobar si hay '\n'
		// si es asi, sale del bucle y devuelve str.
		if (ft_newline(str) == 1)
			break ;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	// Creamos las variables str para guardar los caracteres leidos
	// buffer para almacenar el bufer de lectura, line para la linea
	// resultante y tmp para copiar str.
	static char	*str;
	char		*buffer;
	char		*line;
	char		*tmp;

	tmp = NULL;
	// Si el descriptor o el buffer no son positivos se devuelve NULL.
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// Assignacion de memoria del buffer y comprobacion.
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	// Guardamos el resultado de la funcion ft_read, lee el archivo y
	// comprueba si ha habido algun error o ha llegado al final.
	str = ft_read(fd, buffer, tmp, str);
	if (str == NULL)
		return (NULL);
	line = ft_first_line(str);
	str = ft_after(str);
	return (line);
}
