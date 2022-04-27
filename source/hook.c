/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:20:28 by ebeiline          #+#    #+#             */
/*   Updated: 2022/04/26 17:15:26 by ebeiline         ###   ########.fr       */
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
	return (0);
}
