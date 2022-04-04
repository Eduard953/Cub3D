/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:21:56 by ebeiline          #+#    #+#             */
/*   Updated: 2022/04/04 19:25:26 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->map.tiles = NULL;
	data->map.texture_north = NULL;
	data->map.texture_east = NULL;
	data->map.texture_south = NULL;
	data->map.texture_west = NULL;
	data->map.ceiling_color = -1;
	data->map.floor_color = -1;
	data->map.size.x = 0;
	data->map.size.y = 0;
	data->map.skip = 0;
}

void	error_message(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	exit(1);
}

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

int	get_x_y(t_data *data, char *line, int fd)
{
	data->map.size.x = ft_strlen(line);
	data->map.size.y++;
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

int	main(int argc, char **argv)
{
	t_data	data;
	size_t	i;
	size_t	j;

	check_format(argc, argv);
	init(&data);
	parse(&data, argv);
	check_map(&data);
	i = 0;
	printf("%s\n", data.map.texture_east);
	printf("%s\n", data.map.texture_west);
	printf("%s\n", data.map.texture_north);
	printf("%s\n", data.map.texture_south);
	printf("%d\n", data.map.ceiling_color);
	printf("%d\n", data.map.floor_color);
	while (i < data.map.size.y)
	{
		j = 0;
		while (j < data.map.size.x)
		{
			printf("%c", data.map.tiles[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
