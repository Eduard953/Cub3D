/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 08:14:04 by pstengl           #+#    #+#             */
/*   Updated: 2022/03/31 08:15:00 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <point.h>

t_point	point_create(double x, double y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}
