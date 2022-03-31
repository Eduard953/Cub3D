/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:04:02 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/19 11:19:13 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <ctype.h>

#include "libft.h"

int	main(void)
{
	assert((ft_isascii('c') != 0) == (isascii('c') != 0));
	assert((ft_isascii('9') != 0) == (isascii('9') != 0));
	assert((ft_isascii(4) != 0) == (isascii(4) != 0));
	assert((ft_isascii(0) != 0) == (isascii(0) != 0));
	assert((ft_isascii(2343) != 0) == (isascii(2343) != 0));
	return (0);
}
