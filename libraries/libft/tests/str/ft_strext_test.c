/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strext_bonus_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:45:41 by pstengl           #+#    #+#             */
/*   Updated: 2021/06/17 15:49:13 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <assert.h>

int	main(void)
{
	char	*str;

	str = ft_strdup("Hello World");
	assert(ft_strext(&str, " watcha doin?", 2) != NULL);
	assert(strcmp(str, "Hello World w") == 0);
	assert(ft_strext(&str, "atcha doin?", 11) != NULL);
	assert(strcmp(str, "Hello World watcha doin?") == 0);
	assert(ft_strext(&str, " Nothing", 30) != NULL);
	assert(strcmp(str, "Hello World watcha doin? Nothing") == 0);
	free(str);
	return (0);
}
