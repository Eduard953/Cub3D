/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_bonus_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:01:41 by pstengl           #+#    #+#             */
/*   Updated: 2021/06/17 19:08:01 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "libft.h"

int	main(void)
{
	assert(ft_min(1, 4) == 1);
	assert(ft_min(-2, 5) == -2);
	assert(ft_min(4, 2) == 2);
	assert(ft_min(-4, -2) == -4);
	assert(ft_min(0, 0) == 0);
	assert(ft_min(-3, -3) == -3);
	return (0);
}
