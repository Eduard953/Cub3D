/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:57:36 by pstengl           #+#    #+#             */
/*   Updated: 2022/03/31 13:01:34 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#ifdef __linux__
# include <bsd/string.h>
#else
# include <string.h>
#endif
#include <stdio.h>
#include <string.h>

static void	ft_cmp(char *haystack, char *needle)
{
	int	len;

	len = -1;
	printf("%s:%s:%d\n", haystack, needle, len);
	while (len < 50)
	{
		if (ft_strnstr(haystack, needle, len)
			!= strnstr(haystack, needle, len))
		{
			printf("ft:%s\n", ft_strnstr(haystack, needle, len));
			printf(" c:%s\n", strnstr(haystack, needle, len));
		}
		assert(ft_strnstr(haystack, needle, len)
			== strnstr(haystack, needle, len));
		if (strlen(haystack) == 0 && strlen(needle) != 0)
			assert(ft_strnstr(NULL, needle, len) == NULL);
		if (strlen(haystack) != 0 && strlen(needle) == 0)
			assert(ft_strnstr(haystack, NULL, len) == NULL);
		if (strlen(haystack) == 0 && strlen(needle) == 0)
			assert(ft_strnstr(NULL, NULL, len) == NULL);
		len++;
	}
}

int	main(void)
{
	ft_cmp("Hello World!", "lo");
	ft_cmp("Hello World!", "d!");
	ft_cmp("Hello World!", " W");
	ft_cmp("Hello World!", "l");
	ft_cmp("Hello World!", "XX");
	ft_cmp("Hello World!", "");
	ft_cmp("", "lo");
	ft_cmp("", "d!");
	ft_cmp("", " W");
	ft_cmp("", "l");
	ft_cmp("", "XX");
	ft_cmp("", "");
	ft_cmp("Hi", "This is a very long string, unable to find this one");
	return (0);
}
