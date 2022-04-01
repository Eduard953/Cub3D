/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:24:05 by ebeiline          #+#    #+#             */
/*   Updated: 2022/04/01 15:53:24 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libraries/libft/include/libft.h"
# include "../libraries/gnl/include/gnl.h"

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_map {
	char	**tiles;
	char	*texture_north;
	char	*texture_east;
	char	*texture_south;
	char	*texture_west;
	int		ceiling_color;
	int		floor_color;
	t_coord	size;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	map;
}	t_data;

void	get_x_y(t_data *data, char *line, int *i);

#endif
