/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointtocoord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:22:07 by pstengl           #+#    #+#             */
/*   Updated: 2022/04/24 11:31:37 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"
#include "../cub3d.h"

t_coord	pointtocoord(t_point point)
{
	t_coord	coord;

	coord.x = point.x;
	coord.y = point.y;
	return (coord);
}
