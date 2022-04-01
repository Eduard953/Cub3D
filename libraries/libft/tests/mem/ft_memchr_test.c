/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:41:32 by pstengl           #+#    #+#             */
/*   Updated: 2021/06/06 11:41:34 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

static void	ft_cmp(char *src, char del, int n)
{
	char	*dest1;
	char	*dest2;

	if (del != '\0')
		printf("del: %c, len: %d, src: %s\n", del, n, src);
	else
		printf("del: \\0, len: %d, src: %s\n", n, src);
	dest1 = ft_memchr(src, del, n);
	dest2 = memchr(src, del, n);
	printf("ft:%s\n", dest1);
	printf(" c:%s\n", dest2);
	assert((dest1 != NULL) == (dest2 != NULL));
	if (dest1 && dest2)
		assert(strcmp(dest1, dest2) == 0);
}

int	main(void)
{
	ft_cmp("Hello World", 'l', 8);
	ft_cmp("", 'l', 8);
	ft_cmp("Hello World", 'X', 8);
	ft_cmp("Hello World", 'X', 13);
	ft_cmp("Hello World", 'l', 13);
	ft_cmp("Hello World", '\0', 13);
	ft_cmp("Hello World", 'l', 0);
	return (0);
}
