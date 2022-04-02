/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrext_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:38:55 by pstengl           #+#    #+#             */
/*   Updated: 2022/04/02 15:55:02 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int	main(void)
{
	char	**arr;

	arr = NULL;
	// Add first Element
	ft_arrext(&arr, "Hello World!");
	assert(arr[0] != NULL);
	assert(strcmp(arr[0], "Hello World!") == 0);
	assert(arr[1] == NULL);
	// Add second Element
	ft_arrext(&arr, "Hi there!");
	assert(arr[0] != NULL);
	assert(strcmp(arr[0], "Hello World!") == 0);
	assert(arr[1] != NULL);
	assert(strcmp(arr[1], "Hi there!") == 0);
	assert(arr[2] == NULL);
	// Add 3rd Element
	ft_arrext(&arr, "How are you?");
	assert(arr[0] != NULL);
	assert(strcmp(arr[0], "Hello World!") == 0);
	assert(arr[1] != NULL);
	assert(strcmp(arr[1], "Hi there!") == 0);
	assert(arr[2] != NULL);
	assert(strcmp(arr[2], "How are you?") == 0);
	assert(arr[3] == NULL);
	free(arr);
}
