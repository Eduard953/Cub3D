/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:37:58 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/21 16:44:05 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char	*str1;
	char	*dest1;
	char	*dest2;

	str1 = ft_strdup("Hello World!");
	dest1 = ft_strdup(str1);
	dest2 = strdup(str1);
	assert(strcmp(dest1, dest2) == 0);
	free(str1);
	free(dest1);
	free(dest2);
	str1 = ft_strdup("");
	dest1 = ft_strdup(str1);
	dest2 = strdup(str1);
	assert(strcmp(dest1, dest2) == 0);
	free(str1);
	free(dest1);
	free(dest2);
	return (0);
}
