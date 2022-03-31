/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:41:32 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/21 23:52:16 by pstengl          ###   ########.fr       */
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
	assert(ft_strchr(str, 'l') == strchr(str, 'l'));
	dest1 = ft_strchr(str, 'l');
	dest2 = strchr(str, 'l');
	assert(memcmp(dest1, dest2, 6) == 0);
	dest1 = ft_strchr(str, '\0');
	dest2 = strchr(str, '\0');
	assert(memcmp(dest1, dest2, 1) == 0);
	free(str);
	return (0);
}
