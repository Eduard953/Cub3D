/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:32:11 by pstengl           #+#    #+#             */
/*   Updated: 2022/05/23 13:34:26 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_line_map(t_data *data, char *line, int *found_newline)
{
	size_t	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '\0')
		*found_newline = 1;
	else
	{
		if (*found_newline == 1)
		{
			free(line);
			free_error(data, "Newline in Map");
		}
		if (ft_strlen(line) > data->map.size.x)
			data->map.size.x = ft_strlen(line);
		data->map.size.y++;
	}
	free(line);
}

int	get_x_y(t_data *data, char *line, int fd)
{
	int		found_newline;

	found_newline = 0;
	data->map.size.x = 0;
	check_line_map(data, line, &found_newline);
	while (get_next_line(fd, &line))
	{
		check_line_map(data, line, &found_newline);
	}
	check_line_map(data, line, &found_newline);
	return (0);
}

void	parse_map(t_data *data, char **argv)
{
	size_t	row;
	int		fd;

	row = 0;
	data->map.tiles = ft_calloc((data->map.size.y + 1), sizeof(char *));
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &data->map.tiles[row]) && data->map.skip > 0)
	{
		data->map.skip--;
		free(data->map.tiles[row]);
	}
	row++;
	while (get_next_line(fd, &data->map.tiles[row])
		&& row < data->map.size.y - 1)
		row++;
	close(fd);
}
