/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:44:45 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/27 22:01:41 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include "libft.h"

static void	test(char *str, int start, int len, char *ref)
{
	char	*dest1;

	dest1 = ft_substr(str, start, len);
	assert(strcmp(dest1, ref) == 0);
	free(dest1);
}

int	main(void)
{
	char	*str1;

	str1 = ft_strdup("Hello World!");
	test(str1, 60, 2, "");
	test(str1, 2, 60, "llo World!");
	test(str1, 4, 0, "");
	test(str1, 2, 2, "ll");
	test(str1, 0, 2, "He");
	assert(ft_substr(NULL, 2, 0) == NULL);
	free(str1);
	return (0);
}
