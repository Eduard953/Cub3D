/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:40:39 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/27 21:56:55 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include "libft.h"

static void	ft_cmp(char	*str, char *ref, char *trim)
{
	char	*dest;

	dest = ft_strtrim(str, trim);
	assert(dest != NULL);
	assert(strcmp(dest, ref) == 0);
	free(dest);
}

int	main(void)
{
	ft_cmp("   Hello World    ", "Hello World", " ");
	ft_cmp("Hello World", "Hello World", " ");
	ft_cmp("    Hello World    ", "    Hello World    ", "X");
	assert(ft_strtrim("Hello World", NULL) == NULL);
	assert(ft_strtrim(NULL, " ") == NULL);
	assert(ft_strtrim(NULL, NULL) == NULL);
}
