/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharnec <jcharnec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:35:13 by jcharnec          #+#    #+#             */
/*   Updated: 2023/03/27 17:31:52 by jcharnec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*str1;
	char	*str2;
	char	*ptr;

	str1 = (char *) s1;
	str2 = (char *) s2;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(str1) + ft_strlen(str2);
	ptr = malloc(sizeof(char ) * len + 1);
	if (ptr == NULL)
		return (NULL);
	while (*str1)
	{
		*ptr++ = *str1++;
	}
	while (*str2)
	{
		*ptr++ = *str2++;
	}
	*ptr = '\0';
	return ((char *) ptr - len);
	free (ptr);
}

size_t	ft_strlen(const	char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	free_mem(char *buffer, char *tmp, char *str)
{
	free (buffer);
	free (tmp);
	free (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
