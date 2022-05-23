/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:21:56 by ebeiline          #+#    #+#             */
/*   Updated: 2022/05/23 11:27:15 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_parse(t_data *data)
{
	if (data->map.texture_north.filename == NULL)
		free_error(data, "Missing Texture north");
	if (data->map.texture_east.filename == NULL)
		free_error(data, "Missing Texture east");
	if (data->map.texture_south.filename == NULL)
		free_error(data, "Missing Texture south");
	if (data->map.texture_west.filename == NULL)
		free_error(data, "Missing Texture west");
	if (data->map.ceiling_color == -1)
		free_error(data, "Missing Ceiling color");
	if (data->map.floor_color == -1)
		free_error(data, "Missing Floor color");
}

int	parse_player(t_data *data, size_t i, size_t j)
{
	if (data->map.tiles[i][j] == 'N')
		data->ash.view_angle = 0;
	else if (data->map.tiles[i][j] == 'E')
		data->ash.view_angle = 90;
	else if (data->map.tiles[i][j] == 'S')
		data->ash.view_angle = 180;
	else if (data->map.tiles[i][j] == 'W')
		data->ash.view_angle = 270;
	data->map.tiles[i][j] = '0';
	data->ash.pos.x = j + 0.5;
	data->ash.pos.y = i + 0.5;
	return (1);
}

int	get_x_y(t_data *data, char *line, int fd)
{
	size_t	i;

	i = 0;
	data->map.size.x = ft_strlen(line);
	free(line);
	while (get_next_line(fd, &line))
	{
		if (ft_strlen(line) > data->map.size.x)
			data->map.size.x = ft_strlen(line);
		data->map.size.y++;
		while (line[i] == ' ')
			i++;
		if (line[i] == '\0')
		{
			free(line);
			free_error(data, "newline in map");
		}
		free(line);
	}
	free(line);
	data->map.size.y++;
	data->map.size.y++;
	return (0);
}

void	parse_map(t_data *data, char **argv)
{
	int		row;
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
