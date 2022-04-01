/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:04:02 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/19 11:20:03 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <ctype.h>

#include "libft.h"

int	main(void)
{
	assert((ft_isprint('c') != 0) == (isprint('c') != 0));
	assert((ft_isprint('9') != 0) == (isprint('9') != 0));
	assert((ft_isprint(4) != 0) == (isprint(4) != 0));
	assert((ft_isprint(0) != 0) == (isprint(0) != 0));
	assert((ft_isprint(2343) != 0) == (isprint(2343) != 0));
	return (0);
}
