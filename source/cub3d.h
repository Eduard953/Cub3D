/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ebeiline <ebeiline@42wolfsburg.de>		 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/31 16:24:05 by ebeiline		  #+#	#+#			 */
/*   Updated: 2022/04/25 18:18:01 by pstengl          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define KEY_E			101
# define KEY_ESC		65307
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define ROTA_SPEED		1
# define MOVE_SPEED		0.05
# define WINDOW_WIDTH	800
# define WINDOW_HEIGHT	600
# define FOV			60

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
	int		view_angle;
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
void	rotation_right(t_player *ash);
void	rotation_left(t_player *ash);
void	cast_all_rays(t_data data);
int		angleadd(int base, int add);
void	move_forward(t_data *data);
void	move_backward(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);

#endif
