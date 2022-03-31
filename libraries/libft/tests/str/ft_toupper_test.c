/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:04:02 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/19 11:21:52 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <ctype.h>

#include "libft.h"

int	main(void)
{
	assert(ft_toupper('c') == toupper('c'));
	assert(ft_toupper('C') == toupper('C'));
	assert(ft_toupper('9') == toupper('9'));
	assert(ft_toupper(';') == toupper(';'));
	assert(ft_toupper(4) == toupper(4));
	return (0);
}
