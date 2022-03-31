/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:41:31 by pstengl           #+#    #+#             */
/*   Updated: 2022/03/31 13:01:13 by pstengl          ###   ########.fr       */
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
	char	*src1;
	char	*dest1;
	char	*dest2;

	src1 = ft_strdup("Hello World!");
	dest1 = ft_calloc(ft_strlen(src1) + 4, 1);
	dest2 = ft_calloc(ft_strlen(src1) + 4, 1);
	assert(ft_strlcat(dest1, src1, 12) == strlcat(dest2, src1, 12));
	assert(strcmp(dest1, dest2) == 0);
	assert(ft_strlcat(dest1, src1, 3) == strlcat(dest2, src1, 3));
	assert(strcmp(dest1, dest2) == 0);
	free(dest1);
	free(dest2);
	dest1 = ft_calloc(ft_strlen(src1) + 1, 1);
	dest2 = ft_calloc(ft_strlen(src1) + 1, 1);
	assert(ft_strlcat(dest1, src1, 20) == strlcat(dest2, src1, 20));
	assert(strcmp(dest1, dest2) == 0);
	free(dest1);
	free(dest2);
	free(src1);
	return (0);
}
