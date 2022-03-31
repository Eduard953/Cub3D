/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:05:40 by pstengl           #+#    #+#             */
/*   Updated: 2021/06/05 17:05:24 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

static void	ft_cmp(int n, char *ref)
{
	char	*dest;

	dest = ft_itoa(n);
	printf("%d\nft:%s\n c:%s\n", n, dest, ref);
	assert(strcmp(dest, ref) == 0);
	free(dest);
}

int	main(void)
{
	ft_cmp(42, "42");
	ft_cmp(-42, "-42");
	ft_cmp(0, "0");
	ft_cmp(-2147483648, "-2147483648");
}
