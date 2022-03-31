/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:22:21 by pstengl           #+#    #+#             */
/*   Updated: 2022/03/31 15:34:51 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <assert.h>
#include <stdlib.h>

int	main(void)
{
	char	**arr;

	arr = NULL;
	assert(ft_arrlen(arr) == 0);
	arr = calloc(3, sizeof(char *));
	arr[0] = "Hello World!";
	assert(ft_arrlen(arr) == 1);
	arr[1] = "Hi there";
	assert(ft_arrlen(arr) == 2);
	ft_arrclear(&arr, NULL);
}
