/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharnec <jcharnec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:36:26 by jcharnec          #+#    #+#             */
/*   Updated: 2023/03/28 14:15:02 by jcharnec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	line = malloc(1 * sizeof(char));
	fd = open("test2.txt", O_RDONLY);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
	}
	close (fd);
	return (0);
}
