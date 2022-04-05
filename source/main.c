/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:35:29 by ebeiline          #+#    #+#             */
/*   Updated: 2022/04/05 14:49:35 by ebeiline         ###   ########.fr       */
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
	printf("%f\n", data.ash.view_angle);
	printf("%f\n", data.ash.pos.x);
	printf("%f\n", data.ash.pos.y);
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
