/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:23:32 by pstengl           #+#    #+#             */
/*   Updated: 2021/06/05 20:22:08 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

static void	ft_cmp(char *src, char del, int n)
{
	char	*dest1;
	char	*dest2;

	printf("src: %s, del: %c, len: %d\n", src, del, n);
	dest1 = ft_strdup(src);
	dest2 = ft_strdup(src);
	dest1 = ft_memset(dest1, del, n);
	dest2 = memset(dest2, del, n);
	printf("ft:%s\n", dest1);
	printf(" c:%s\n", dest2);
	assert((dest1 != NULL) == (dest2 != NULL));
	if (dest1 && dest2)
		assert(ft_memcmp(dest1, dest2, n) == 0);
	free(dest1);
	free(dest2);
}

int	main(void)
{
	ft_cmp("Hello World", 'X', 5);
	ft_cmp("Hello World", 'X', 0);
	return (0);
}
