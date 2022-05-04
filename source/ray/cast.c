/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pstengl <pstengl@student.42wolfsburg.	  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/04/24 11:19:04 by pstengl		   #+#	#+#			 */
/*   Updated: 2022/05/04 11:02:29 by pstengl          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include <math.h>
#include "../coord.h"
#include "../point/point.h"
#include "../cub3d.h"
#include "ray.h"
#include "precomp.h"
#include <stdio.h>

static t_precomp	ray_precompute(t_point pos, double angle)
{
	t_precomp	precomp;
	t_coord		map_xy;

	map_xy = pointtocoord(pos);
	precomp.ray_dir_x = sin(degtorad(angle));
	precomp.ray_dir_y = -cos(degtorad(angle));
	precomp.delta_dist_x = fabs(1 / precomp.ray_dir_x);
	precomp.delta_dist_y = fabs(1 / precomp.ray_dir_y);
	precomp.step_x = 1;
	precomp.step_y = 1;
	precomp.side_dist_x = (map_xy.x + 1.0 - pos.x) * precomp.delta_dist_x;
	precomp.side_dist_y = (map_xy.y + 1.0 - pos.y) * precomp.delta_dist_y;
	if (precomp.ray_dir_x < 0)
	{
		precomp.step_x = -1;
		precomp.side_dist_x = (pos.x - map_xy.x) * precomp.delta_dist_x;
	}
	if (precomp.ray_dir_y < 0)
	{
		precomp.step_y = -1;
		precomp.side_dist_y = (pos.y - map_xy.y) * precomp.delta_dist_y;
	}
	return (precomp);
}

static void	advance_ray(t_precomp *precomp, t_ray *ray, t_coord *coords)
{
	if (precomp->side_dist_x < precomp->side_dist_y)
	{
		precomp->side_dist_x += precomp->delta_dist_x;
		coords->x += precomp->step_x;
		ray->side = 'W';
		if (precomp->ray_dir_x > 0)
			ray->side = 'E';
	}
	else
	{
		precomp->side_dist_y += precomp->delta_dist_y;
		coords->y += precomp->step_y;
		ray->side = 'N';
		if (precomp->ray_dir_y > 0)
			ray->side = 'S';
	}
}

t_ray	ray_cast(t_map map, t_point pos, double angle)
{
	t_precomp	precomp;
	t_ray		ray;
	t_coord		coords;
	int			counter;

	counter = 0;
	coords = pointtocoord(pos);
	precomp = ray_precompute(pos, angle);
	while (counter < 100)
	{
		advance_ray(&precomp, &ray, &coords);
		if (map.tiles[coords.y][coords.x] != '0')
			break ;
		counter++;
	}
	ray.tile = map.tiles[coords.y][coords.x];
	if (ray.side == 'E' || ray.side == 'W')
	{
		ray.distance = precomp.side_dist_x - precomp.delta_dist_x;
		ray.wall_x = pos.y + ray.distance * precomp.ray_dir_y;
	}
	else
	{
		ray.distance = precomp.side_dist_y - precomp.delta_dist_y;
		ray.wall_x = pos.x + ray.distance * precomp.ray_dir_x;
	}
	ray.wall_x -= floor(ray.wall_x);
	return (ray);
}
