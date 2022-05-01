/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:22:49 by pstengl           #+#    #+#             */
/*   Updated: 2022/05/01 13:39:57 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "../point/point.h"
# include "../cub3d.h"

typedef struct s_ray {
	double	distance;
	char	side;
}	t_ray;

t_ray	ray_cast(t_map map, t_point pos, int angle);
t_ray	door_ray_cast(t_map map, t_point pos, int angle);

#endif
