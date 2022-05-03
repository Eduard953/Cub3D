/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:27:03 by pstengl           #+#    #+#             */
/*   Updated: 2022/05/02 15:34:49 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	angleadd(double base, double add)
{
	double	new_angle;

	new_angle = (base + add);
	if (new_angle < 0.0)
		new_angle = new_angle + 360.0;
	if (new_angle > 360.0)
		new_angle = new_angle - 360.0;
	return (new_angle);
}

double	degtorad(double deg)
{
	return ((deg * M_PI) / 180.0);
}
