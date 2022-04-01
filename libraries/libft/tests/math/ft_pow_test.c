/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_bonus_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:42:59 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/20 15:46:33 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "libft.h"

int	main(void)
{
	assert(ft_pow(3, 5) == 243);
	assert(ft_pow(-3, 3) == -27);
	assert(ft_pow(3, -3) == 0);
	assert(ft_pow(0, -3) == 0);
	assert(ft_pow(0, 3) == 0);
	assert(ft_pow(3, 0) == 1);
	return (0);
}
