/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:45:48 by pstengl           #+#    #+#             */
/*   Updated: 2022/05/19 16:22:18 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_block(t_data data, t_coord pos, unsigned int size,
		unsigned int color)
{
	t_size	coords;
	t_size	scale_pos;

	scale_pos.x = pos.x * size;
	scale_pos.y = pos.y * size;
	coords.x = scale_pos.x;
	while (coords.x < scale_pos.x + size)
	{
		coords.y = scale_pos.y;
		while (coords.y < scale_pos.y + size)
		{
			image_pixel_put(data, coords.x, coords.y, color);
			coords.y++;
		}
		coords.x++;
	}
}

static void	choose_block(t_data data, t_coord pos)
{
	if (data.map.tiles[pos.y][pos.x] == '0')
		draw_block(data, pos, 10, 0xFF000000);
	else if (data.map.tiles[pos.y][pos.x] == '1')
		draw_block(data, pos, 10, 0xFF595959);
	else if (data.map.tiles[pos.y][pos.x] == '2')
	{
		if (!check_door_state(data.map, pos))
			draw_block(data, pos, 10, 0xFFdb8a34);
		else
			draw_block(data, pos, 10, 0xFF34db8a);
	}
}

void	draw_minimap(t_data data)
{
	t_coord	pos;
	t_coord	player_pos;

	pos.x = 0;
	while ((size_t)pos.x < data.map.size.x)
	{
		pos.y = 0;
		while ((size_t)pos.y < data.map.size.y)
		{
			choose_block(data, pos);
			pos.y++;
		}
		pos.x++;
	}
	player_pos.x = data.ash.pos.x;
	player_pos.y = data.ash.pos.y;
	draw_block(data, player_pos, 10, 0xFFFFFFFF);
}
