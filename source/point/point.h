/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 08:11:56 by pstengl           #+#    #+#             */
/*   Updated: 2022/04/24 11:31:55 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H
# include "../coord.h"

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

t_point	point_create(double x, double y);
t_coord	pointtocoord(t_point point);

#endif
