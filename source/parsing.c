/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:21:56 by ebeiline          #+#    #+#             */
/*   Updated: 2022/05/23 13:32:48 by pstengl          ###   ########.fr       */
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
