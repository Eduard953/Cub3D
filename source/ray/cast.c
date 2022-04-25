/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pstengl <pstengl@student.42wolfsburg.	  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/04/24 11:19:04 by pstengl		   #+#	#+#			 */
/*   Updated: 2022/04/25 12:15:42 by pstengl          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include <math.h>
#include "../coord.h"
#include "../point/point.h"
#include "../cub3d.h"
#include "ray.h"
#include "precomp.h"
#include <stdio.h>

t_precomp	ray_precompute(t_point pos, int angle)
{
	t_precomp	precomp;
	double		ray_dir_x;
	double		ray_dir_y;
	t_coord		map_xy;

	map_xy = pointtocoord(pos);
	ray_dir_x = sin(degtorad(angle));
	ray_dir_y = -cos(degtorad(angle));
	precomp.delta_dist_x = fabs(1 / ray_dir_x);
	precomp.delta_dist_y = fabs(1 / ray_dir_y);
	precomp.step_x = 1;
	precomp.step_y = 1;
	precomp.side_dist_x = (map_xy.x + 1.0 - pos.x) * precomp.delta_dist_x;
	precomp.side_dist_y = (map_xy.y + 1.0 - pos.y) * precomp.delta_dist_y;
	if (ray_dir_x < 0)
	{
		precomp.step_x = -1;
		precomp.side_dist_x = (pos.x - map_xy.x) * precomp.delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		precomp.step_y = -1;
		precomp.side_dist_y = (pos.y - map_xy.y) * precomp.delta_dist_y;
	}
	return (precomp);
}

t_ray	ray_cast(t_map map, t_point pos, int angle)
{
	t_precomp	precomp;
	t_ray		ray;
	t_coord		coords;

	coords = pointtocoord(pos);
	precomp = ray_precompute(pos, angle);
	while (1)
	{
		if (precomp.side_dist_x < precomp.side_dist_y)
		{
			precomp.side_dist_x += precomp.delta_dist_x;
			coords.x += precomp.step_x;
			ray.side = 0;
		}
		else
		{
			precomp.side_dist_y += precomp.delta_dist_y;
			coords.y += precomp.step_y;
			ray.side = 1;
		}
		if (map.tiles[coords.y][coords.x] != '0')
			break ;
	}
	if (ray.side == 0)
		ray.distance = precomp.side_dist_x - precomp.delta_dist_x;
	else
		ray.distance = precomp.side_dist_y - precomp.delta_dist_y;
	return (ray);
}