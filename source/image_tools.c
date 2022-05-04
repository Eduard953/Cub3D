/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:13:03 by pstengl           #+#    #+#             */
/*   Updated: 2022/05/04 12:46:26 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image_clear(void *mlx, void *img)
{
	char	*img_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	img_addr = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
	ft_memset(img_addr, mlx_get_color_value(mlx, 0xFF000000),
		WINDOW_WIDTH * WINDOW_HEIGHT * (bits_per_pixel / 8));
}

void	image_pixel_put(t_data data, int x, int y, unsigned int color)
{
	char	*img_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	img_addr = mlx_get_data_addr(data.img, &bits_per_pixel, &size_line,
			&endian);
	if (x < 0 || x > WINDOW_WIDTH)
		return ;
	if (y < 0 || y > WINDOW_HEIGHT)
		return ;
	color = mlx_get_color_value(data.mlx, color);
	int pixel = (y * size_line) + (x * (bits_per_pixel / 8));
    if (endian == 1)        // Most significant (Alpha) byte first
    {
        img_addr[pixel + 0] = (color >> 24);
        img_addr[pixel + 1] = (color >> 16) & 0xFF;
        img_addr[pixel + 2] = (color >> 8) & 0xFF;
        img_addr[pixel + 3] = (color) & 0xFF;
    }
    else if (endian == 0)   // Least significant (Blue) byte first
    {
        img_addr[pixel + 0] = (color) & 0xFF;
        img_addr[pixel + 1] = (color >> 8) & 0xFF;
        img_addr[pixel + 2] = (color >> 16) & 0xFF;
        img_addr[pixel + 3] = (color >> 24);
    }
}
