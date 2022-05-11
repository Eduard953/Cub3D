/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:47:14 by pstengl           #+#    #+#             */
/*   Updated: 2022/05/11 17:37:53 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ray/ray.h"

static t_texture	choose_texture(t_data data, t_ray ray)
{
	t_texture	texture;

	if (ray.tile == '1')
	{
		if (ray.side == 'N')
			texture = data.map.texture_north;
		else if (ray.side == 'S')
			texture = data.map.texture_south;
		else if (ray.side == 'W')
			texture = data.map.texture_west;
		else
			texture = data.map.texture_east;
	}
	else
		texture = data.map.texture_door;
	return (texture);
}

static unsigned int	get_color(t_texture texture, t_ray ray, int tex_pos)
{
	t_size			tex_coord;
	unsigned int	color;

	tex_coord.x = ray.wall_x * (double)texture.width;
	if (ray.side == 'E')
		tex_coord.x = texture.width - tex_coord.x - 1;
	if (ray.side == 'S')
		tex_coord.x = texture.width - tex_coord.x - 1;
	tex_coord.y = tex_pos & (texture.height - 1);
	color = texture.data[texture.width * tex_coord.y + tex_coord.x];
	if (ray.side == 'W' || ray.side == 'E')
		color = (color >> 1) & 8355711;
	return (color);
}

static void	draw_wide_pixel(t_data data, int x, int y, unsigned int color)
{
	int	idx;

	idx = 0;
	while (idx < GFX_QUALITY + 1)
	{
		image_pixel_put(data, x + idx, y, color);
		idx++;
	}
}

void	draw_wall(t_data data, t_ray ray, int x)
{
	int				draw;
	int				draw_end;
	double			step;
	double			tex_pos;
	t_texture		texture;

	texture = choose_texture(data, ray);
	draw = ft_max(-(WINDOW_HEIGHT / ray.distance) / 2 + WINDOW_HEIGHT / 2.0, 0);
	draw_end = ft_min((WINDOW_HEIGHT / ray.distance) / 2 + WINDOW_HEIGHT / 2.0,
			WINDOW_HEIGHT - 1);
	step = 1.0 * texture.height / (WINDOW_HEIGHT / ray.distance);
	tex_pos = (draw - WINDOW_HEIGHT / 2.0
			+ (WINDOW_HEIGHT / ray.distance) / 2.0) * step;
	while (draw < draw_end)
	{
		draw_wide_pixel(data, x, draw, get_color(texture, ray, tex_pos));
		tex_pos += step;
		draw++;
	}
}
