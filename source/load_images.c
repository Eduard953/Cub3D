/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:45:28 by pstengl           #+#    #+#             */
/*   Updated: 2022/05/23 11:52:10 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_images(t_data	*data)
{
	data->map.texture_north = load_texture(data->mlx,
			data->map.texture_north.filename);
	if (data->map.texture_north.data == NULL)
		free_error(data, "Could not load texture north\n");
	data->map.texture_south = load_texture(data->mlx,
			data->map.texture_south.filename);
	if (data->map.texture_south.data == NULL)
		free_error(data, "Could not load texture south\n");
	data->map.texture_east = load_texture(data->mlx,
			data->map.texture_east.filename);
	if (data->map.texture_east.data == NULL)
		free_error(data, "Could not load texture east\n");
	data->map.texture_west = load_texture(data->mlx,
			data->map.texture_west.filename);
	if (data->map.texture_west.data == NULL)
		free_error(data, "Could not load texture west\n");
	data->map.texture_door = load_texture(data->mlx, "data/textures/wood.xpm");
	if (data->map.texture_door.data == NULL)
		free_error(data, "Could not load texture door\n");
}
