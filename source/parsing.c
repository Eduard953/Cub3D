/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:21:56 by ebeiline          #+#    #+#             */
/*   Updated: 2022/04/02 15:19:00 by ebeiline         ###   ########.fr       */
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
}

void	get_x_y(t_data *data, char *line, int fd)
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
}

void	parse_map(t_data *data, char **argv, int i)
{
	int		row;
	int		fd;

	row = 0;
	data->map.tiles = malloc((data->map.size.y + 1) * sizeof(char *));
	data->map.tiles[data->map.size.y] = NULL;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &data->map.tiles[row]) && i > 0)
	{
		i--;
	}
	while (get_next_line(fd, &data->map.tiles[row]))
		row++;
	close(fd);
}

void	parse(t_data *data, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "map not found", 14);
		exit(-1);
	}
	i = 0;
	while (get_next_line(fd, &line) && parse_line(data, line, fd, &i))
		free(line);
	close(fd);
	parse_map(data, argv, i);
}

int	main(int argc, char **argv)
{
	t_data	data;
	size_t	i;
	size_t	j;

	check_format(argc, argv);
	init(&data);
	parse(&data, argv);
	i = 0;
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
