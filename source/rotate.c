/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:27:39 by ebeiline          #+#    #+#             */
/*   Updated: 2022/04/26 16:59:44 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotation_left(t_player *ash)
{
	ash->view_angle -= ROTA_SPEED;
	if (ash->view_angle < 0)
		ash->view_angle = 360;
}

void	rotation_right(t_player *ash)
{
	ash->view_angle += ROTA_SPEED;
	if (ash->view_angle > 360)
		ash->view_angle = 0;
	printf("%d\n", ash->view_angle);
}
