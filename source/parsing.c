/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:21:56 by ebeiline          #+#    #+#             */
/*   Updated: 2022/04/27 19:31:57 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_parse(t_data *data)
{
	if (data->map.texture_north == NULL)
		error_message("no texture north");
	if (data->map.texture_east == NULL)
		error_message("no texture east");
	if (data->map.texture_south == NULL)
		error_message("no texture south");
	if (data->map.texture_west == NULL)
		error_message("no texture west");
	if (data->map.ceiling_color == -1)
		error_message("no ceiling color");
	if (data->map.floor_color == -1)
		error_message("no floor color");
}

int	parse_player(t_data *data, size_t i, size_t j)
{
	if (data->map.tiles[i][j] == 'N')
		data->ash.view_angle = 0;
	else if (data->map.tiles[i][j] == 'W')
		data->ash.view_angle = 90;
	else if (data->map.tiles[i][j] == 'S')
		data->ash.view_angle = 180;
	else if (data->map.tiles[i][j] == 'E')
		data->ash.view_angle = 270;
	data->map.tiles[i][j] = '0';
	data->ash.pos.x = j + 0.5;
	data->ash.pos.y = i + 0.5;
	return (1);
}

int	get_x_y(t_data *data, char *line, int fd)
{
	data->map.size.x = ft_strlen(line);
	free(line);
	while (get_next_line(fd, &line))
	{
		if (ft_strlen(line) > data->map.size.x)
			data->map.size.x = ft_strlen(line);
		data->map.size.y++;
		free(line);
	}
	data->map.size.y++;
	return (0);
}

void	parse_map(t_data *data, char **argv)
{
	int		row;
	int		fd;

	row = 0;
	data->map.tiles = malloc((data->map.size.y + 1) * sizeof(char *));
	data->map.tiles[data->map.size.y] = NULL;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &data->map.tiles[row]) && data->map.skip >= 0)
	{
		data->map.skip--;
	}
	while (get_next_line(fd, &data->map.tiles[row]))
		row++;
	close(fd);
}

void	parse(t_data *data, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		error_message("fd error");
	}
	while (get_next_line(fd, &line) && parse_line(data, line, fd))
		free(line);
	close(fd);
	parse_map(data, argv);
	check_parse(data);
}
