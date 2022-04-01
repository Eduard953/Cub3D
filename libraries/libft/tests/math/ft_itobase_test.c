/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobase_bonus_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:59:13 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/21 20:25:59 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include "libft.h"

static void	ft_test(int n, char *base, char *ref)
{
	char	*dest;

	dest = ft_itobase(n, base);
	assert(strcmp(dest, ref) == 0);
	free(dest);
}

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
	ft_test(256, hex, "100");
	ft_test(-45, hex, "-2D");
	ft_test(256, dec, "256");
	ft_test(-45, dec, "-45");
	ft_test(256, oct, "400");
	ft_test(-45, oct, "-55");
	ft_test(256, bin, "100000000");
	ft_test(-45, bin, "-101101");
}
