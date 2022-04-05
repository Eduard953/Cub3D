/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:56:11 by ebeiline          #+#    #+#             */
/*   Updated: 2022/04/05 12:52:34 by ebeiline         ###   ########.fr       */
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

void	check_tiles(t_data *data)
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
				p++;
			j++;
		}
		i++;
	}
	if (p != 1)
		error_message("invalid amount of spawning points");
}

void	check_map(t_data *data)
{
	check_tiles(data);
//	check_walls(data);
}
