/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:31:11 by pstengl           #+#    #+#             */
/*   Updated: 2022/03/31 15:34:39 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int	main(void)
{
	char	**arr1;
	char	**arr2;

	arr2 = ft_arrdup(NULL);
	assert(arr2 == NULL);
	arr1 = calloc(3, sizeof(char *));
	arr1[0] = "Hello World!";
	arr1[1] = "Hi there!";
	arr2 = ft_arrdup(arr1);
	assert(arr2 != NULL);
	assert(strcmp(arr2[0], "Hello World!") == 0);
	assert(strcmp(arr2[1], "Hi there!") == 0);
	ft_arrclear(&arr1, NULL);
	ft_arrclear(&arr2, free);
}
