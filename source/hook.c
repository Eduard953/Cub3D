/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:20:28 by ebeiline          #+#    #+#             */
/*   Updated: 2022/04/25 13:26:27 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keys(int key, t_data *data)
{
	if (key == ESC)
		red_cross(data);
	else if (key == W_MAC)
		move_forward(data);
	else if (key == S_MAC)
		move_backward(data);
	else if (key == A_MAC)
		move_left(data);
	else if (key == D_MAC)
		move_right(data);
	else if (key == LEFT)
		rotate_left(data);
	else if (key == RIGHT)
		rotate_right(data);
	return (0);
}
