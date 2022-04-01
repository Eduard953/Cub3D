/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:46:08 by pstengl           #+#    #+#             */
/*   Updated: 2021/06/05 20:00:40 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

static void	ft_cmp(char	*str1, char *str2, int n)
{
	int	res1;
	int	res2;

	printf("str1: %s, str2: %s, len: %d\n", str1, str2, n);
	res1 = ft_memcmp(str1, str2, n);
	res2 = memcmp(str1, str2, n);
	printf("ft:%d\n", res1);
	printf(" c:%d\n", res2);
	assert(res1 == res2);
}

int	main(void)
{
	ft_cmp("Hello World", "Hello Worrd", 0);
	ft_cmp("Hello World", "Hello Worrd", 6);
	ft_cmp("Hello World", "Hello Worrd", 12);
	ft_cmp("", "Hello World!", 1);
	ft_cmp("Hello World", "", 1);
	return (0);
}
