/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:35:29 by ebeiline          #+#    #+#             */
/*   Updated: 2022/05/23 11:30:04 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ray/ray.h"

void	error_message(char *message)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	init(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->map.tiles = NULL;
	data->map.texture_north.filename = NULL;
	data->map.texture_east.filename = NULL;
	data->map.texture_south.filename = NULL;
	data->map.texture_west.filename = NULL;
	data->map.texture_door.filename = NULL;
	data->map.ceiling_color = -1;
	data->map.floor_color = -1;
	data->map.size.x = 0;
	data->map.size.y = 0;
	data->map.skip = 0;
	data->map.doors = NULL;
	data->map.door_num = 0;
	data->mouse_x = WINDOW_WIDTH / 2;
}

int	loop(t_data *data)
{
	image_clear(*data, data->img);
	cast_all_rays(*data);
	draw_minimap(*data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	check_format(argc, argv);
	init(&data);
	parse(&data, argv);
	check_map(&data);
	data.mlx = mlx_init();
	load_images(&data);
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D");
	mlx_hook(data.win, 17, 0L, red_cross, &data);
	mlx_hook(data.win, 2, 1L << 0, keys, &data);
	mlx_hook(data.win, 6, 1L << 6, mouse_move, &data);
	mlx_loop_hook(data.mlx, loop, &data);
	data.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_loop(data.mlx);
	return (0);
}
