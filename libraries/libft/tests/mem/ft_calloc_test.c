/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:24:36 by pstengl           #+#    #+#             */
/*   Updated: 2021/06/06 11:46:04 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static void	ft_cmp(int nb, int size)
{
	void	*dest1;
	void	*dest2;

	printf("%d, %d\n", nb, size);
	dest1 = ft_calloc(nb, size);
	dest2 = calloc(nb, size);
	assert((dest1 != NULL) == (dest2 != NULL));
	if (dest1 != NULL && dest2 != NULL)
		assert(memcmp(dest1, dest2, nb * size) == 0);
	if (dest1 != NULL)
		free(dest1);
	if (dest2 != NULL)
		free(dest2);
}

int	main(void)
{
	ft_cmp(0, 0);
	ft_cmp(0, 6);
	ft_cmp(6, 0);
	ft_cmp(4, 6);
	ft_cmp(432385, 87468326);
	return (0);
}
