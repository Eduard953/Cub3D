/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:35:17 by pstengl           #+#    #+#             */
/*   Updated: 2022/04/25 11:46:37 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ray/ray.h"

static void	draw_vertical(t_data data, int x, int width, int height)
{
	int	x_select;
	int	y_select;
	int	y;

	y = (WINDOW_HEIGHT / 2) - (height / 2);
	x_select = 0;
	while (x_select < width)
	{
		y_select = 0;
		while (y_select < height)
		{
			mlx_pixel_put(data.mlx, data.win, x + x_select, y + y_select,
				0xFFFF00FF);
			y_select++;
		}
		x_select++;
	}
}

void	cast_all_rays(t_data data)
{
	t_ray	ray;
	int		index;
	int		offset;
	int		angle;

	offset = data.ash.view_angle - (FOV / 2);
	index = 0;
	while (index < FOV)
	{
		angle = angleadd(offset, index);
		ray = ray_cast(data.map, data.ash.pos, angle);
		draw_vertical(data, index * 10, 10, (WINDOW_HEIGHT / ray.distance));
		index++;
	}
}
