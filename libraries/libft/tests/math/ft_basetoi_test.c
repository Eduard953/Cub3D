/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basetoi_bonus_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:59:13 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/21 20:06:10 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char	*hex;
	char	*dec;
	char	*oct;
	char	*bin;

	hex = "0123456789ABCDEF";
	dec = "0123456789";
	oct = "01234567";
	bin = "01";
	assert(ft_basetoi("100", hex) == 256);
	assert(ft_basetoi("-2D", hex) == -45);
	assert(ft_basetoi("256", dec) == 256);
	assert(ft_basetoi("-45", dec) == -45);
	assert(ft_basetoi("400", oct) == 256);
	assert(ft_basetoi("-55", oct) == -45);
	assert(ft_basetoi("100000000", bin) == 256);
	assert(ft_basetoi("-101101", bin) == -45);
	assert(ft_basetoi("HAHAHA", dec) == 0);
}
