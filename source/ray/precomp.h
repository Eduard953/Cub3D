/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precomp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:23:32 by pstengl           #+#    #+#             */
/*   Updated: 2022/04/24 11:34:19 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRECOMP_H
# define PRECOMP_H

typedef struct s_precomp
{
	int		step_x;
	int		step_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
}	t_precomp;

#endif
