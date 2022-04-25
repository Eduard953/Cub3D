/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ebeiline <ebeiline@42wolfsburg.de>		 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/31 16:24:05 by ebeiline		  #+#	#+#			 */
/*   Updated: 2022/04/25 16:58:35 by pstengl          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define W		119
# define A		97
# define S		115
# define D		100
# define E		101
# define ESC	65307
# define LEFT	65361
# define RIGHT	65363

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "point/point.h"
# include "../libraries/libft/include/libft.h"
# include "../libraries/gnl/include/gnl.h"
# include "../libraries/mlx/mlx.h"

typedef struct s_size
{
	size_t	x;
	size_t	y;
}	t_size;

typedef struct s_player
{
	t_point	pos;
	double	view_angle;
}	t_player;

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
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	ash;
}	t_data;

int		parse_line(t_data *data, char *line, int fd);
void	check_format(int argc, char **argv);
void	error_message(char *message);
void	check_map(t_data *data);
int		get_x_y(t_data *data, char *line, int fd);
int		parse_player(t_data *data, size_t i, size_t j);
void	parse(t_data *data, char **argv);
int		red_cross(t_data *data);
int		keys(int key, t_data *data);
double	degtorad(int deg);

#endif
