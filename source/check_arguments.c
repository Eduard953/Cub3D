/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:56:11 by ebeiline          #+#    #+#             */
/*   Updated: 2022/04/05 14:35:00 by ebeiline         ###   ########.fr       */
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
			error_message("top not surrounded by walls");
		i++;
	}
	i = 0;
	while (data->map.tiles[data->map.size.y - 1][i] != '\0')
	{
		if (ft_strchr("1 ", data->map.tiles[data->map.size.y - 1][i]) == NULL)
			error_message("bottom not surrounded by walls");
		i++;
	}
}

void	check_spaces(t_data *data, size_t i, size_t j)
{
	if (data->map.tiles[i - 1][j] == ' ')
		error_message("map not surrounded by walls");
	if (data->map.tiles[i + 1][j] == ' ')
		error_message("map not surrounded by walls");
	if (data->map.tiles[i][j - 1] == ' ')
		error_message("map not surrounded by walls");
	if (data->map.tiles[i][j + 1] == ' ')
		error_message("map not surrounded by walls");
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
			error_message("map not surrounded by walls");
		while (data->map.tiles[i][j])
		{
			if (ft_strchr("NSEW0", data->map.tiles[i][j])
				&& data->map.tiles[i][j] != '\0')
				check_spaces(data, i, j);
			j++;
		}
		if (data->map.tiles[i][j - 1] != '1')
			error_message("map not surrounded by walls");
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
	while (i < data->map.size.y)
	{
		j = 0;
		while (j < data->map.size.x)
		{
			if (ft_strchr("01NSEW ", data->map.tiles[i][j]) == NULL)
				error_message("invalid map");
			else if (ft_strchr("NSEW", data->map.tiles[i][j])
				&& data->map.tiles[i][j] != '\0')
				p += parse_player(data, i, j);
			j++;
		}
		i++;
	}
	if (p != 1)
		error_message("invalid amount of spawning points");
	check_walls(data);
}
