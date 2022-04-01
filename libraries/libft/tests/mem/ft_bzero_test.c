/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:24:40 by pstengl           #+#    #+#             */
/*   Updated: 2021/06/05 19:23:35 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	*space1;
	char	*space2;

	space1 = ft_strdup("Hello World!");
	space2 = ft_strdup("Hello World!");
	ft_bzero(space1, 5);
	bzero(space2, 5);
	printf("ft:%s\n", space1);
	printf(" c:%s\n", space2);
	assert(memcmp(space1, space2, 12) == 0);
	free(space1);
	free(space2);
}
