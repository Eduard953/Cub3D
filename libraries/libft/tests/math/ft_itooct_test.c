/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itooct_bonus_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:59:13 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/21 20:12:54 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char	*result;

	result = ft_itooct(256);
	assert(strcmp(result, "400") == 0);
	free(result);
	result = ft_itooct(-45);
	assert(strcmp(result, "-55") == 0);
	free(result);
	return (0);
}
