/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:13:03 by pstengl           #+#    #+#             */
/*   Updated: 2022/05/11 12:04:44 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image_clear(t_data data, void *img)
{
	unsigned int	*img_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				idx;

	img_addr = (unsigned int *)mlx_get_data_addr(img, &bits_per_pixel,
			&size_line, &endian);
	idx = 0;
	while (idx < WINDOW_WIDTH * (WINDOW_HEIGHT / 2))
	{
		img_addr[idx] = mlx_get_color_value(data.mlx, data.map.ceiling_color);
		idx++;
	}
	while (idx < WINDOW_WIDTH * WINDOW_HEIGHT)
	{
		img_addr[idx] = mlx_get_color_value(data.mlx, data.map.floor_color);
		idx++;
	}
}

void	image_pixel_put(t_data data, int x, int y, unsigned int color)
{
	int		*img_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	img_addr = (int *)mlx_get_data_addr(data.img, &bits_per_pixel, &size_line,
			&endian);
	if (x < 0 || x >= WINDOW_WIDTH)
		return ;
	if (y < 0 || y >= WINDOW_HEIGHT)
		return ;
	color = mlx_get_color_value(data.mlx, color);
	img_addr[y * WINDOW_WIDTH + x] = color;
}
