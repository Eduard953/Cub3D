/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:24:05 by ebeiline          #+#    #+#             */
/*   Updated: 2022/04/02 15:38:04 by ebeiline         ###   ########.fr       */
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

typedef struct s_size
{
	size_t	x;
	size_t	y;
}	t_size;

typedef struct s_map {
	char	**tiles;
	char	*texture_north;
	char	*texture_east;
	char	*texture_south;
	char	*texture_west;
	int		ceiling_color;
	int		floor_color;
	int		skip;
	t_size	size;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	map;
}	t_data;

void	get_x_y(t_data *data, char *line, int fd);
int		parse_line(t_data *data, char *line, int fd);
void	check_format(int argc, char **argv);

#endif
