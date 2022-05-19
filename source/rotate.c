/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:27:39 by ebeiline          #+#    #+#             */
/*   Updated: 2022/05/19 19:45:25 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotation_left(t_player *ash)
{
	ash->view_angle = angleadd(ash->view_angle, -ROTA_SPEED);
}

void	rotation_right(t_player *ash)
{
	ash->view_angle = angleadd(ash->view_angle, ROTA_SPEED);
}
