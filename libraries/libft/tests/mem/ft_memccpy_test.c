/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:41:08 by pstengl           #+#    #+#             */
/*   Updated: 2022/03/31 13:04:32 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static void	ft_cmp(void *src, char del, int n)
{
	char	*dest1;
	char	*dest2;

	dest1 = calloc(1, 20);
	dest2 = calloc(1, 20);
	ft_memccpy(dest1, src, del, n);
	memccpy(dest2, src, del, n);
	if (del != '\0')
		printf("delimiter: %c, len: %d, src: %s\n", del, n, (char *)src);
	else
		printf("delimiter: \\0, len: %d, src: %s\n", n, (char *)src);
	printf("ft:%s\n", dest1);
	printf(" c:%s\n", dest2);
	assert((dest1 != NULL) == (dest2 != NULL));
	if (dest1 && dest2)
		assert(memcmp(dest1, dest2, 20) == 0);
	free(dest1);
	free(dest2);
}

int	main(void)
{
	ft_cmp("Hello World!", 'l', 10);
	ft_cmp("", 'X', 5);
	ft_cmp("Hello World!", 'X', 10);
	ft_cmp("Hello World!", 'o', 2);
	ft_cmp("Hello World!", '\0', 8);
	ft_cmp("Hello World!", '\0', 23);
	ft_cmp("Hello World!", 'o', 13);
	ft_cmp("Hello World!", 'X', 13);
	ft_cmp("Hello World!", 'X', 0);
	return (0);
}
