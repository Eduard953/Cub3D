/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ebeiline <ebeiline@42wolfsburg.de>		 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/31 16:24:05 by ebeiline		  #+#	#+#			 */
/*   Updated: 2022/05/19 16:27:25 by pstengl          ###   ########.fr       */
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
# define ROTA_SPEED		2
# define MOVE_SPEED		0.05
# define WINDOW_WIDTH	800
# define WINDOW_HEIGHT	600
# define FOV			60
# define WALL_DIST		0.25
# define GFX_QUALITY	1
# define DOOR_DIST		1
# define MINIMAP_SIZE	0.3

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "point/point.h"
# include "../libraries/libft/include/libft.h"
# include "../libraries/gnl/include/gnl.h"
# include "../libraries/mlx/mlx.h"

typedef struct s_ray	t_ray;

typedef struct s_size
{
	size_t	x;
	size_t	y;
}	t_size;

typedef struct s_texture {
	char	*filename;
	int		*data;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	void	*mlx_img_ptr;
}	t_texture;

typedef struct s_player
{
	t_point	pos;
	double	view_angle;
}	t_player;

typedef struct s_door
{
	t_point	pos;
	int		open;
}	t_door;

typedef struct s_map {
	char		**tiles;
	t_texture	texture_north;
	t_texture	texture_east;
	t_texture	texture_south;
	t_texture	texture_west;
	t_texture	texture_door;
	int			ceiling_color;
	int			floor_color;
	int			skip;
	t_size		size;
	int			door_num;
	t_door		*doors;
}	t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	int			mouse_x;
	t_map		map;
	t_player	ash;
}	t_data;

int			parse_line(t_data *data, char *line, int fd);
void		check_format(int argc, char **argv);
void		error_message(char *message);
void		check_map(t_data *data);
int			get_x_y(t_data *data, char *line, int fd);
int			parse_player(t_data *data, size_t i, size_t j);
void		parse(t_data *data, char **argv);
int			red_cross(t_data *data);
int			keys(int key, t_data *data);
double		degtorad(double deg);
void		rotation_right(t_player *ash);
void		rotation_left(t_player *ash);
void		cast_all_rays(t_data data);
double		angleadd(double base, double add);
void		move_forward(t_data *data);
void		move_backward(t_data *data);
void		move_right(t_data *data);
void		move_left(t_data *data);
void		image_clear(t_data data, void *img);
void		image_pixel_put(t_data data, int x, int y, unsigned int color);
t_texture	load_texture(void *mlx, char *filename);
void		load_images(t_data	*data);
void		draw_wall(t_data data, t_ray ray, int x);
int			check_door_state(t_map map, t_coord coords);
void		add_door(t_data *data, size_t i, size_t j);
void		door_change_state(t_data *data);
int			mouse_move(int x, int y, t_data *data);
void		draw_minimap(t_data data);

#endif
