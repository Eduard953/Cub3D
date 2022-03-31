/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:41:47 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/21 17:10:57 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>

#include "libft.h"

int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = ft_strdup("Hello World!");
	str2 = ft_strdup("Hello Wurld!");
	assert((ft_strncmp(str1, str2, 10) < 0) == (strncmp(str1, str2, 10) < 0));
	assert(ft_strncmp(str1, str2, 3) == strncmp(str1, str2, 3));
	free(str1);
	free(str2);
	return (0);
}
