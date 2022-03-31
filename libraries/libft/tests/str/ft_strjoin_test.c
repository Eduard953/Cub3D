/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:30:22 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/21 16:44:56 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char	*str1;
	char	*str2;
	char	*dest;

	str1 = ft_strdup("Hello ");
	str2 = ft_strdup("World!");
	dest = ft_strjoin(str1, str2);
	assert(dest != NULL);
	assert(strcmp(dest, "Hello World!") == 0);
	free(str1);
	free(str2);
	free(dest);
	return (0);
}
