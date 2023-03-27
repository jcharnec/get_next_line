/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharnec <jcharnec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:56:06 by jcharnec          #+#    #+#             */
/*   Updated: 2023/03/27 20:32:01 by jcharnec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	ptr = (char *)malloc(sizeof(char) * (i + 2));
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

char	*ft_last_line(char *str)
{
	int		i;
	int		j;
	char	*ptr;

	j = 0;
	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[j] != '\n' && str[j] != '\0')
		j++;
	if (str[j] == '\0')
	{
		free(str);
		return (NULL);
	}
	ptr = malloc(sizeof(char) * (ft_strlen(str) - j + 1));
	if (ptr == NULL)
		return (NULL);
	j += 1;
	while (str[j] != '\0')
		ptr[i++] = str[j++];
	ptr[i] = '\0';
	free(str);
	return (ptr);
}

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

char	*ft_read(int fd, char *buffer, char *tmp, char *str)
{
	int		i;

	i = 1;
	while (i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free_mem(buffer, tmp, str);
			return (NULL);
		}
		buffer[i] = '\0';
		tmp = str;
		if (tmp == NULL)
			tmp = ft_strdup("");
		str = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_newline(str) == 1)
			break ;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*buffer;
	char		*line;
	char		*tmp;

	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
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
