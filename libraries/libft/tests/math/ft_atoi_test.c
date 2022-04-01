/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:48:53 by pstengl           #+#    #+#             */
/*   Updated: 2021/09/08 20:48:00 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

static void	ft_cmp(char *test)
{
	printf("%s\nft:%d\n c:%d\n", test, ft_atoi(test), atoi(test));
	assert(ft_atoi(test) == atoi(test));
}

int	main(void)
{
	ft_cmp("123456789");
	ft_cmp("4376543fgfr373");
	ft_cmp("  4327543");
	ft_cmp("  -4392872");
	ft_cmp("  +49632");
	ft_cmp("-8543");
	ft_cmp("+86434");
	ft_cmp("");
	ft_cmp("+--+-+76438");
	ft_cmp("--967423");
	ft_cmp("+++8743");
	ft_cmp("+-+-");
	ft_cmp("-");
	return (0);
}
