/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_bonus_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:51:05 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/20 15:54:23 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "libft.h"

int	main(void)
{
	assert(ft_sqrt(25) == 5);
	assert(ft_sqrt(-25) == 0);
	assert(ft_sqrt(0) == 0);
	assert(ft_sqrt(24) == 0);
}
