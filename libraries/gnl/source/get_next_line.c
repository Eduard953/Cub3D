/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 19:17:24 by pstengl           #+#    #+#             */
/*   Updated: 2021/09/09 18:47:40 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line_utils.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 64
#endif

static int	read_and_prune(char buffer[BUFFER_SIZE], ssize_t read_chars,
		char **line)
{
	int		hit_newline;
	ssize_t	chars_until_nl;

	chars_until_nl = 0;
	while (chars_until_nl < read_chars && buffer[chars_until_nl] != '\n')
		chars_until_nl++;
	if (ft_strext(line, buffer, chars_until_nl) == NULL)
		return (-1);
	hit_newline = 0;
	if (buffer[chars_until_nl] == '\n')
		hit_newline = 1;
	ft_prune_front(buffer, chars_until_nl + 1, BUFFER_SIZE);
	return (hit_newline);
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE];
	ssize_t		read_chars;
	int			hit_newline;

	*line = NULL;
	while (1)
	{
		read_chars = BUFFER_SIZE;
		if (*buffer == '\0')
		{
			read_chars = read(fd, buffer, BUFFER_SIZE);
			if (read_chars == -1)
				return (-1);
			if (read_chars == 0)
			{
				if (*line == NULL)
					*line = ft_calloc(sizeof(char *), 1);
				return (0);
			}
		}
		hit_newline = read_and_prune(buffer, read_chars, line);
		if (hit_newline)
			return (1);
	}
	return (1);
}
