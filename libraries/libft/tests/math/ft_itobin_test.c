/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobin_bonus_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:59:13 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/21 20:21:05 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char	*result;

	result = ft_itobin(256);
	assert(strcmp(result, "100000000") == 0);
	free(result);
	result = ft_itobin(-45);
	assert(strcmp(result, "-101101") == 0);
	free(result);
	return (0);
}
