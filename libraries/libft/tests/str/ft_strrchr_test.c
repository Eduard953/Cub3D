/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:41:32 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/21 17:03:49 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>

#include "libft.h"

int	main(void)
{
	char	*str;
	char	*dest1;
	char	*dest2;

	str = ft_strdup("Hello World!");
	assert(ft_strrchr(str, 'l') == strrchr(str, 'l'));
	dest1 = ft_strrchr(str, 'l');
	dest2 = strrchr(str, 'l');
	assert(memcmp(dest1, dest2, 4) == 0);
	free(str);
	return (0);
}
