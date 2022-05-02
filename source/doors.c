/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 12:10:29 by ebeiline          #+#    #+#             */
/*   Updated: 2022/05/02 10:56:53 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ray/ray.h"

void	door_change_state(t_data *data)
{
	int		i;
	t_ray	door_dist;

	i = 0;
	while (i < data->map.door_num)
	{
		door_dist = door_ray_cast(data->map, data->ash.pos,
				data->ash.view_angle);
		if (door_dist.distance < DOOR_DIST)
			data->map.doors[i].open = !data->map.doors[i].open;
		i++;
	}
}

int	check_door_state(t_map map, t_coord coords)
{
	int	i;

	i = 0;
	while (i < map.door_num)
	{
		if (map.doors[i].pos.x == coords.x && map.doors[i].pos.y == coords.y)
			return (map.doors[i].open);
		i++;
	}
	error_message("door not found");
	return (-1);
}

void	add_door(t_data *data, size_t i, size_t j)
{
	if (!data->map.doors)
	{
		data->map.doors = malloc(sizeof(struct s_door) * data->map.door_num);
		data->map.door_num = 0;
		if (!data->map.doors)
			error_message("malloc of door struct failed");
	}
	data->map.doors[data->map.door_num].pos.x = j;
	data->map.doors[data->map.door_num].pos.y = i;
	data->map.doors[data->map.door_num].open = 0;
	data->map.door_num++;
}
