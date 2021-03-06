/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:56:11 by ebeiline          #+#    #+#             */
/*   Updated: 2022/05/24 17:46:28 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_format(int argc, char **argv)
{
	int	len;

	if (argc < 2)
	{
		printf("too few args");
		exit(1);
	}
	if (argc > 2)
	{
		printf("too many args");
		exit(1);
	}
	len = ft_strlen(argv[1]);
	if (len < 5 || ft_strnstr(argv[1] + len - 4, ".cub", 4) == NULL)
	{
		printf("use .cub map");
		exit(1);
	}
}

void	check_top_bottom(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->map.tiles[0][i] != '\0')
	{
		if (ft_strchr("1 ", data->map.tiles[0][i]) == NULL)
			free_error(data, "top not surrounded by walls");
		i++;
	}
	i = 0;
	while (data->map.tiles[data->map.size.y - 1][i] != '\0')
	{
		if (ft_strchr("1 ", data->map.tiles[data->map.size.y - 1][i]) == NULL)
			free_error(data, "bottom not surrounded by walls");
		i++;
	}
}

void	check_spaces(t_data *data, size_t i, size_t j)
{
	if (data->map.tiles[i - 1][j] == ' ' || data->map.tiles[i - 1][j] == '\0')
		free_error(data, "map not surrounded by walls");
	if (data->map.tiles[i + 1][j] == ' ' || data->map.tiles[i + 1][j] == '\0')
		free_error(data, "map not surrounded by walls");
	if (data->map.tiles[i][j - 1] == ' ' || data->map.tiles[i][j - 1] == '\0')
		free_error(data, "map not surrounded by walls");
	if (data->map.tiles[i][j + 1] == ' ' || data->map.tiles[i][j + 1] == '\0')
		free_error(data, "map not surrounded by walls");
}

void	check_walls(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	check_top_bottom(data);
	while (i < data->map.size.y)
	{
		j = 0;
		while (data->map.tiles[i][j] == ' ')
			j++;
		if (data->map.tiles[i][j] != '1')
			free_error(data, "map not surrounded by walls");
		while (data->map.tiles[i][j])
		{
			if (ft_strchr("NSEW02", data->map.tiles[i][j])
				&& data->map.tiles[i][j] != '\0')
				check_spaces(data, i, j);
			if (data->map.tiles[i][j] == '2')
				data->map.door_num++;
			j++;
		}
		if (data->map.tiles[i][j - 1] != '1')
			free_error(data, "map not surrounded by walls");
		i++;
	}
}

void	check_map(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	p;

	i = 0;
	p = 0;
	check_walls(data);
	while (i < data->map.size.y)
	{
		j = 0;
		while (j < data->map.size.x)
		{
			if (ft_strchr("012NSEW ", data->map.tiles[i][j]) == NULL)
				free_error(data, "invalid map");
			else if (ft_strchr("NSEW", data->map.tiles[i][j])
				&& data->map.tiles[i][j] != '\0')
				p += parse_player(data, i, j);
			else if (data->map.tiles[i][j] == '2')
				add_door(data, i, j);
			j++;
		}
		i++;
	}
	if (p != 1)
		free_error(data, "invalid amount of spawning points");
}
