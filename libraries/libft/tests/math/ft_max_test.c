/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_bonus_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:01:41 by pstengl           #+#    #+#             */
/*   Updated: 2021/06/17 19:03:27 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "libft.h"

int	main(void)
{
	assert(ft_max(1, 4) == 4);
	assert(ft_max(-2, 5) == 5);
	assert(ft_max(4, 2) == 4);
	assert(ft_max(-4, -2) == -2);
	assert(ft_max(0, 0) == 0);
	assert(ft_max(-3, -3) == -3);
	return (0);
}
