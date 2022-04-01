/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:04:02 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/19 11:22:17 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <ctype.h>

#include "libft.h"

int	main(void)
{
	assert(ft_tolower('c') == tolower('c'));
	assert(ft_tolower('C') == tolower('C'));
	assert(ft_tolower('9') == tolower('9'));
	assert(ft_tolower(';') == tolower(';'));
	assert(ft_tolower(4) == tolower(4));
	return (0);
}
