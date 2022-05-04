/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:35:17 by pstengl           #+#    #+#             */
/*   Updated: 2022/05/04 12:49:29 by pstengl          ###   ########.fr       */
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
				0xFF00FF00);
			y_select++;
		}
		x_select++;
	}
}

static void draw_wall(t_data data, t_ray ray, int x) {
	int height;
	t_texture	tex;

	if (ray.side == 'N')
		tex = data.map.texture_north;
	else if (ray.side == 'S')
		tex = data.map.texture_south;
	else if (ray.side == 'W')
		tex = data.map.texture_west;
	else
		tex = data.map.texture_east;
	height = WINDOW_HEIGHT / ray.distance;
	int texX = ray.wall_x * (double)tex.width;
	if(ray.side == 'E') texX = tex.width - texX - 1;
	if(ray.side == 'S') texX = tex.width - texX - 1;
	double step = 1.0 * tex.height / height;
	double texPos = ((-height / 2.0 + WINDOW_HEIGHT / 2.0) - WINDOW_HEIGHT / 2.0 + height / 2.0) * step;
	for(int y = (-height / 2 + WINDOW_HEIGHT / 2); y<(height / 2 + WINDOW_HEIGHT / 2); y++)
	{
		int texY = (int)texPos & (tex.height - 1);
		texPos += step;
		unsigned int color = tex.data[(tex.size_line * texY) + (texX * (tex.bits_per_pixel / 8))];
		if(ray.side == 'W' || ray.side == 'E') color = (color >> 1) & 8355711;
		image_pixel_put(data, x, y, color);
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
		if (ray.tile == '1')
			draw_wall(data, ray, index * GFX_QUALITY);
		else {
			if (ray.distance < 1)
				ray.distance = 1;
			draw_vertical(data, index * GFX_QUALITY, GFX_QUALITY + 1,
					(WINDOW_HEIGHT / ray.distance));
		}
		index++;
	}
}
