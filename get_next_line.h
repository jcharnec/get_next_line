/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharnec <jcharnec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:35:26 by jcharnec          #+#    #+#             */
/*   Updated: 2023/03/22 18:47:22 by jcharnec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *buf, char *tmp, char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const	char *str);
char	*ft_first_line(char *str);
char	*ft_after(char *str);
int		ft_newline(char *str);

#endif
