/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:20:28 by ebeiline          #+#    #+#             */
/*   Updated: 2022/05/19 19:44:55 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include "ray/ray.h"

int	cast_ray(t_data data, int offset)
{
	t_ray	ray;

	ray = ray_cast(data.map, data.ash.pos,
			angleadd(data.ash.view_angle, offset));
	if (ray.distance < WALL_DIST)
		return (1);
	return (0);
}

void	move_forward(t_data *data)
{
	double	dx;
	double	dy;

	dy = cos(degtorad(data->ash.view_angle)) * MOVE_SPEED;
	dx = -sin(degtorad(data->ash.view_angle)) * MOVE_SPEED;
	if (!cast_ray(*data, 0))
	{
		data->ash.pos.x -= dx;
		data->ash.pos.y -= dy;
	}
}

void	move_backward(t_data *data)
{
	double	dx;
	double	dy;

	dy = cos(degtorad(data->ash.view_angle)) * MOVE_SPEED;
	dx = -sin(degtorad(data->ash.view_angle)) * MOVE_SPEED;
	if (!cast_ray(*data, 180))
	{
		data->ash.pos.x += dx;
		data->ash.pos.y += dy;
	}
}

void	move_left(t_data *data)
{
	double	dx;
	double	dy;

	dy = -sin(degtorad(data->ash.view_angle)) * MOVE_SPEED;
	dx = -cos(degtorad(data->ash.view_angle)) * MOVE_SPEED;
	if (!cast_ray(*data, 270))
	{
		data->ash.pos.x += dx;
		data->ash.pos.y += dy;
	}
}

void	move_right(t_data *data)
{
	double	dx;
	double	dy;

	dy = sin(degtorad(data->ash.view_angle)) * MOVE_SPEED;
	dx = cos(degtorad(data->ash.view_angle)) * MOVE_SPEED;
	if (!cast_ray(*data, 90))
	{
		data->ash.pos.x += dx;
		data->ash.pos.y += dy;
	}
}
