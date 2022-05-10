/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:22:49 by pstengl           #+#    #+#             */
/*   Updated: 2022/05/10 09:55:45 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "../point/point.h"
# include "../cub3d.h"

typedef struct s_ray {
	double	distance;
	double	wall_x;
	char	side;
	char	tile;
}	t_ray;

t_ray	ray_cast(t_map map, t_point pos, double angle);
t_ray	door_ray_cast(t_map map, t_point pos, double angle);

#endif
