/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:41:31 by pstengl           #+#    #+#             */
/*   Updated: 2022/03/31 13:01:03 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#ifdef __linux__
# include <bsd/string.h>
#else
# include <string.h>
#endif
#include "libft.h"

int	main(void)
{
	char	*str1;
	char	*dest1;
	char	*dest2;

	str1 = ft_strdup("Hello World!");
	dest1 = calloc(ft_strlen(str1) + 1, 1);
	dest2 = calloc(ft_strlen(str1) + 1, 1);
	assert(ft_strlcpy(dest1, str1, 12) == strlcpy(dest2, str1, 12));
	free(dest1);
	free(dest2);
	dest1 = calloc(ft_strlen(str1) + 1, 1);
	dest2 = calloc(ft_strlen(str1) + 1, 1);
	assert(ft_strlcpy(dest1, str1, 4) == strlcpy(dest2, str1, 4));
	free(dest1);
	free(dest2);
	dest1 = calloc(ft_strlen(str1) + 1, 1);
	dest2 = calloc(ft_strlen(str1) + 1, 1);
	assert(ft_strlcpy(dest1, str1, 18) == strlcpy(dest2, str1, 18));
	free(str1);
	free(dest1);
	free(dest2);
	return (0);
}
