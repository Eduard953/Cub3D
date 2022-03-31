/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:30:53 by pstengl           #+#    #+#             */
/*   Updated: 2021/06/05 20:06:44 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

static void	ft_cmp(char	*src, int n)
{
	char	*dest1;
	char	*dest2;

	printf("src: %s, len: %d\n", src, n);
	dest1 = calloc(1, strlen(src) + 1);
	dest2 = calloc(1, strlen(src) + 1);
	ft_memcpy(dest1, src, n);
	memcpy(dest2, src, n);
	printf("ft:%s\n", dest1);
	printf(" c:%s\n", dest2);
	assert((dest1 != NULL) == (dest2 != NULL));
	if (dest1 && dest2)
		assert(memcmp(dest1, dest2, strlen(src)) == 0);
	free(dest1);
	free(dest2);
}

int	main(void)
{
	ft_cmp("Hello World!", 12);
	ft_cmp("", 1);
	ft_cmp("Hello World!", 5);
	return (0);
}
