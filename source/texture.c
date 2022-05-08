/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:18:46 by pstengl           #+#    #+#             */
/*   Updated: 2022/05/04 20:44:31 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	load_texture(void *mlx, char *filename)
{
	t_texture	texture;

	texture.filename = filename;
	texture.mlx_img_ptr = mlx_xpm_file_to_image(mlx, filename,
			&(texture.width), &(texture.height));
	if (!texture.mlx_img_ptr)
	{
		printf("READING XPM FILE FAILED!");
		texture.data = NULL;
		return (texture);
	}
	texture.data = (int *)mlx_get_data_addr(texture.mlx_img_ptr,
			&(texture.bits_per_pixel), &(texture.size_line), &(texture.endian));
	return (texture);
}
