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

int main()
{
	int 	fd1;
	int 	fd2;
	int 	fd3;
	char    *line;
	int		ret;

	fd1 = open("test1.txt", O_RDONLY);
	if (fd1 == -1)
	{
		perror("Error opening text1.txt");
		return (1);
	}
		fd2 = open("test2.txt", O_RDONLY);
	if (fd2 == -1)
	{
		perror("Error opening text2.txt");
		close(fd1);
		return (1);
	}
		fd3 = open("test3.txt", O_RDONLY);
	if (fd3 == -1)
	{
		perror("Error opening text3.txt");
		close(fd3);
		close(fd2);
		return (1);
	}
}