/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:35:17 by pstengl           #+#    #+#             */
/*   Updated: 2022/05/02 16:15:55 by pstengl          ###   ########.fr       */
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
			image_pixel_put(data, x + x_select, y + y_select,
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
	double	offset;
	double	angle;
	double	scale;

	scale = ((double)FOV / ((double)WINDOW_WIDTH / (double)GFX_QUALITY));
	offset = data.ash.view_angle - (FOV / 2.0);
	index = 0;
	while (index < ((double)WINDOW_WIDTH / (double)GFX_QUALITY))
	{
		angle = angleadd(offset, index * scale);
		ray = ray_cast(data.map, data.ash.pos, angle);
		if (ray.distance < 1)
			ray.distance = 1;
		draw_vertical(data, index * GFX_QUALITY, GFX_QUALITY + 1,
			(WINDOW_HEIGHT / ray.distance));
		index++;
	}
}
