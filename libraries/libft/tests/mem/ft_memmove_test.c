/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:41:18 by pstengl           #+#    #+#             */
/*   Updated: 2021/06/05 20:16:09 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

static void	ft_cmp(char *str, int offset, int n)
{
	char	*src1;
	char	*src2;
	char	*dest1;
	char	*dest2;

	src1 = ft_strdup(str);
	src2 = ft_strdup(str);
	printf("src1: %s, src2: %s, len: %d, offset: %d\n", src1, src2, n, offset);
	dest1 = (src1 + offset);
	dest2 = (src2 + offset);
	dest1 = ft_memmove(dest1, src1, n);
	dest2 = memmove(dest2, src2, n);
	printf("ft:%s\n", dest1);
	printf(" c:%s\n", dest2);
	assert(memcmp(dest1, dest2, ft_strlen(str) - offset) == 0);
	assert(memcmp(src1, src2, ft_strlen(str)) == 0);
	free(src1);
	free(src2);
}

int	main(void)
{
	ft_cmp("Hello World!", 3, 5);
	ft_cmp("Hello World!", 0, 5);
	ft_cmp("Hello World!", 3, 0);
	ft_cmp("", 0, 1);
	return (0);
}
