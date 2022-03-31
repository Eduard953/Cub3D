/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:12:00 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/21 18:45:14 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include "libft.h"

static char	ft_repl_l(unsigned int i, char c)
{
	if (i > 0)
		if (c == 'l')
			return ('X');
	return (c);
}

static char	ft_set_num(unsigned int i, char c)
{
	if (i < 10)
		return (i + 48);
	return (c);
}

int	main(void)
{
	char	*result;

	result = ft_strmapi("Hello World!", ft_repl_l);
	assert(strcmp(result, "HeXXo WorXd!") == 0);
	free(result);
	result = ft_strmapi("", ft_repl_l);
	assert(strcmp(result, "") == 0);
	free(result);
	result = ft_strmapi("Hey how you", ft_set_num);
	assert(strcmp(result, "0123456789u") == 0);
	free(result);
	return (0);
}
