/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:20:28 by ebeiline          #+#    #+#             */
/*   Updated: 2022/04/27 19:55:45 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	move_forward(t_data *data)
{
	double	dx;
	double	dy;
	
	dy = cos(degtorad(data->ash.view_angle)) * MOVE_SPEED;
	dx = sin(degtorad(data->ash.view_angle)) * MOVE_SPEED;
	if (data->map.tiles[(int)(data->ash.pos.y - dy)][(int)(data->ash.pos.x - dx)] == '0')
	{
		data->ash.pos.x -= dx;
		data->ash.pos.y -= dy;
	}
	printf("Position: %f, %f\n", data->ash.pos.x, data->ash.pos.y);
}

void	move_backward(t_data *data)
{
	double	dx;
	double	dy;
	
	dy = cos(degtorad(data->ash.view_angle)) * MOVE_SPEED;
	dx = sin(degtorad(data->ash.view_angle)) * MOVE_SPEED;
	printf("delta x: %f, delta y: %f\n", dx, dy);
	if (data->map.tiles[(int)(data->ash.pos.y + dy)][(int)(data->ash.pos.x + dx)] == '0')
	{
		data->ash.pos.x += dx;
		data->ash.pos.y += dy;
	}
	printf("Position: %f, %f\n", data->ash.pos.x, data->ash.pos.y);
}

void	move_left(t_data *data)
{
	double	dx;
	double	dy;
	
	dy = cos(degtorad((data->ash.view_angle - 90) % 360)) * MOVE_SPEED;
	dx = sin(degtorad((data->ash.view_angle - 90) % 360)) * MOVE_SPEED;
	if (data->map.tiles[(int)(data->ash.pos.y + dy)][(int)(data->ash.pos.x + dx)] == '0')
	{
		data->ash.pos.x += dx;
		data->ash.pos.y += dy;
	}
	printf("Position: %f, %f\n", data->ash.pos.x, data->ash.pos.y);
}

void   move_right(t_data *data)
{
	double	dx;
	double	dy;
	
	dy = cos(degtorad((data->ash.view_angle + 90) % 360)) * MOVE_SPEED;
	dx = sin(degtorad((data->ash.view_angle + 90) % 360)) * MOVE_SPEED;
	if (data->map.tiles[(int)(data->ash.pos.y + dy)][(int)(data->ash.pos.x + dx)] == '0')
	{
		data->ash.pos.x += dx;
		data->ash.pos.y += dy;
	}
	printf("Position: %f, %f\n", data->ash.pos.x, data->ash.pos.y);
}
