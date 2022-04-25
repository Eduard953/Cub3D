/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:27:39 by ebeiline          #+#    #+#             */
/*   Updated: 2022/04/25 17:46:52 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotation_left(t_player ash)
{
	ash.view_angle -= ROTATION;
	if (ash.view_angle < 0)
		ash.view_angle = 360;
}

void	rotation_right(t_player ash)
{
	ash.view_angle += ROTATION;
	if (ash.view_angle > 360)
		ash.view_angle = 0;
}
