/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:04:02 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/19 11:16:13 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <ctype.h>

#include "libft.h"

int	main(void)
{
	assert(ft_isdigit('c') == isdigit('c'));
	assert((ft_isdigit('9') != 0) == (isdigit('9') != 0));
	assert(ft_isdigit(4) == isdigit(4));
	assert(ft_isdigit(';') == isdigit(';'));
	return (0);
}
