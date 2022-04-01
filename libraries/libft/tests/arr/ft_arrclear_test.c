/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrclear_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:57:59 by pstengl           #+#    #+#             */
/*   Updated: 2022/03/31 15:11:05 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <assert.h>

static void check_ro(void)
{
	char	**arr;

	arr = calloc(3, sizeof(char *));
	arr[0] = "Hello World";
	arr[1] = "Hi there!";
	ft_printarr(arr);
	ft_arrclear(&arr, NULL);
	assert(arr == NULL);
}

static void check_malloc(void)
{
	char	**arr;

	arr = calloc(3, sizeof(char *));
	arr[0] = ft_strdup("Hello World");
	arr[1] = ft_strdup("Hi there!");
	ft_printarr(arr);
	ft_arrclear(&arr, free);
	assert(arr == NULL);
}

int	main(void)
{
	char	**arr;

	arr = NULL;
	ft_arrclear(&arr, NULL);
	assert(arr == NULL);
	ft_arrclear(&arr, free);
	assert(arr == NULL);
	check_ro();
	check_malloc();
	return (0);
}
