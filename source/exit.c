/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:19:35 by ebeiline          #+#    #+#             */
/*   Updated: 2022/05/11 17:38:33 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	end_game(t_data *data)
{
	size_t	i;

	i = 0;
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_image(data->mlx, data->map.texture_north.mlx_img_ptr);
	mlx_destroy_image(data->mlx, data->map.texture_east.mlx_img_ptr);
	mlx_destroy_image(data->mlx, data->map.texture_west.mlx_img_ptr);
	mlx_destroy_image(data->mlx, data->map.texture_south.mlx_img_ptr);
	mlx_destroy_image(data->mlx, data->map.texture_door.mlx_img_ptr);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	while (i < data->map.size.y)
	{
		free(data->map.tiles[i]);
		i++;
	}
	free(data->map.tiles);
	return (0);
}

int	red_cross(t_data *data)
{
	printf("Game aborted");
	end_game(data);
	exit(EXIT_SUCCESS);
	return (0);
}
