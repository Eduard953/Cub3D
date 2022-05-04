/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:35:17 by pstengl           #+#    #+#             */
/*   Updated: 2022/05/04 20:43:13 by pstengl          ###   ########.fr       */
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

static void	draw_wall(t_data data, t_ray ray, int x)
{
	int				height;
	int				draw;
	int				draw_end;
	double			step;
	double			tex_pos;
	unsigned int	color;
	t_size			tex_coord;
	t_texture		texture;

	if (ray.side == 'N')
		texture = data.map.texture_north;
	else if (ray.side == 'S')
		texture = data.map.texture_south;
	else if (ray.side == 'W')
		texture = data.map.texture_west;
	else
		texture = data.map.texture_east;

	tex_coord.x = ray.wall_x * (double)texture.width;
	if (ray.side == 'E')
		tex_coord.x = texture.width - tex_coord.x - 1;
	if (ray.side == 'S')
		tex_coord.x = texture.width - tex_coord.x - 1;

	height = WINDOW_HEIGHT / ray.distance;
	draw = -height / 2 + WINDOW_HEIGHT / 2;
	if (draw < 0)
		draw = 0;
	draw_end = height / 2 + WINDOW_HEIGHT / 2;
	if (draw_end >= WINDOW_HEIGHT)
		draw_end = WINDOW_HEIGHT - 1;
	step = 1.0 * texture.height / height;
	tex_pos = (draw - WINDOW_HEIGHT / 2.0 + height / 2.0) * step;
	while (draw < draw_end)
	{
		tex_coord.y = (int)tex_pos & (texture.height - 1);
		tex_pos += step;
		color = texture.data[texture.width * tex_coord.y + tex_coord.x];
		if (ray.side == 'W' || ray.side == 'E')
			color = (color >> 1) & 8355711;
		image_pixel_put(data, x, draw, color);
		draw++;
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
		else
		{
			if (ray.distance < 1)
				ray.distance = 1;
			draw_vertical(data, index * GFX_QUALITY, GFX_QUALITY + 1,
				(WINDOW_HEIGHT / ray.distance));
		}
		index++;
	}
}
