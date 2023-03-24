/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharnec <jcharnec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:56:06 by jcharnec          #+#    #+#             */
/*   Updated: 2023/03/24 13:22:30 by jcharnec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		return (NULL);
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

// Funcion para obtener la cadena despues de '\n', Declaramo 3 variables, 
// i para contar el numero de caracteres, j para buscar el primer '\n' y ptr 
// para guardar el contenido despues de '\n'
char	*ft_last_line(char *str)
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
	ptr = malloc(sizeof(char) * ft_strlen(str) -j + 1);
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

// Funcion que sirve para leer el archivo, inicializo i en 1 para 
// cotrolar el bucle de lectura, con un bucle controlamos llegar al
// final del archivo a leer, guardamos en i el numero de bytes
// del descriptor. Assignamos '\0' al buffer y guardamos el str
// en el tmp, si este nos devuelve NULL sera la primera vez que
// leemos el archivo y le asignamos memoria para 1 caracter.
// al final despues de concatenar llamamos la funcion st_newline
// para comprobar si hay '\n' y salir del bucle.
char	*ft_read(int fd, char *buffer, char *tmp, char *str)
{
	int		i;

	i = 1;
	while (i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free_mem(buffer, str);
			return (NULL);
		}
		buffer[i] = '\0';
		tmp = str;
		if (tmp == NULL)
		{
			tmp = malloc(sizeof(char));
			tmp[0] = '\0';
		}
		str = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_newline(str) == 1)
			break ;
	}
	free(buffer);
	return (str);
}

// Creo las variables str para guardar los caracteres leidos,
// buffer para almacenar el bufer de lectura, line para la linea
// resultante y tmp para copiar str.
// Guardamos el resultado de la funcion ft_read, lee el archivo y
// comprueba si ha habido algun error o ha llegado al final.
char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*buffer;
	char		*line;
	char		*tmp;

	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	str[fd] = ft_read(fd, buffer, tmp, str[fd]);
	if (str[fd] == NULL)
		return (NULL);
	line = ft_first_line(str[fd]);
	str[fd] = ft_last_line(str[fd]);
	if (line == NULL && str[fd] == NULL)
	{
		free(str[fd]);
		return (NULL);
	}
	return (line);
}
