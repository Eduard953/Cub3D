/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:38:36 by pstengl           #+#    #+#             */
/*   Updated: 2022/05/23 11:33:57 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_error(t_data *data, char *msg)
{
	free_data(data);
	error_message(msg);
}

static void	free_texture(t_texture tex)
{
	if (tex.filename)
		free(tex.filename);
}

static void	free_maptiles(t_map map)
{
	size_t	y;

	if (!map.tiles)
		return ;
	y = 0;
	while (y < map.size.y + 1)
	{
		free(map.tiles[y]);
		y++;
	}
	free(map.tiles);
}

void	free_data(t_data *data)
{
	free_texture(data->map.texture_east);
	free_texture(data->map.texture_west);
	free_texture(data->map.texture_north);
	free_texture(data->map.texture_south);
	free_maptiles(data->map);
	if (data->map.doors)
		free(data->map.doors);
}
