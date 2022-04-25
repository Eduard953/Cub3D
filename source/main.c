/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:35:29 by ebeiline          #+#    #+#             */
/*   Updated: 2022/04/25 13:19:17 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ray/ray.h"

void	error_message(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	exit(1);
}

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
	t_ray	ray;

	check_format(argc, argv);
	init(&data);
	parse(&data, argv);
	check_map(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.map.size.x * 32,
			data.map.size.y * 32, "CUB3D");
	mlx_hook(data.win, 17, 0L, red_cross, &data);
	mlx_hook(data.win, 2, 1L << 0, keys, &data);
	ray = ray_cast(data.map, data.ash.pos, 326);
	printf("side: %d, distance %f\n", ray.side, ray.distance);
	mlx_loop(data.mlx);
	return (0);
}
