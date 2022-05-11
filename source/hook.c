/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:20:28 by ebeiline          #+#    #+#             */
/*   Updated: 2022/05/11 17:38:48 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keys(int key, t_data *data)
{
	if (key == KEY_ESC)
		red_cross(data);
	else if (key == KEY_W)
		move_forward(data);
	else if (key == KEY_S)
		move_backward(data);
	else if (key == KEY_A)
		move_left(data);
	else if (key == KEY_D)
		move_right(data);
	else if (key == KEY_LEFT)
		rotation_left(&data->ash);
	else if (key == KEY_RIGHT)
		rotation_right(&data->ash);
	else if (key == KEY_E)
		door_change_state(data);
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	if (x < data->mouse_x)
		rotation_left(&data->ash);
	else if (x > data->mouse_x)
		rotation_right(&data->ash);
	data->mouse_x = x;
	if (y || !y)
		return (0);
	return (0);
}
