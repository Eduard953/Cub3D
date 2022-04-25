/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:27:03 by pstengl           #+#    #+#             */
/*   Updated: 2022/04/25 11:21:08 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int	angleadd(int base, int add)
{
	int	new_angle;

	new_angle = (base + add) % 360;
	if (new_angle < 0)
		new_angle = 360 + new_angle;
	return (new_angle);
}

double	degtorad(int deg)
{
	return ((deg * M_PI) / 180.0);
}
