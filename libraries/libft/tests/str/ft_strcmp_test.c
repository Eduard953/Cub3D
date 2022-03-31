/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_bonus_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:41:47 by pstengl           #+#    #+#             */
/*   Updated: 2021/06/23 18:42:45 by pstengl          ###   ########.fr       */
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
	assert((ft_strcmp(str1, str2) < 0) == (strcmp(str1, str2) < 0));
	free(str1);
	free(str2);
	return (0);
}
