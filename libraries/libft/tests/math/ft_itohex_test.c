/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex_bonus_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:59:13 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/21 20:10:42 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char	*result;

	result = ft_itohex(256);
	assert(strcmp(result, "100") == 0);
	free(result);
	result = ft_itohex(-45);
	assert(strcmp(result, "-2D") == 0);
	free(result);
	return (0);
}
