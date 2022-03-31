/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:04:02 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/19 11:14:09 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <ctype.h>

#include "libft.h"

int	main(void)
{
	assert((ft_isalpha('c') != 0) == (isalpha('c') != 0));
	assert(ft_isalpha('9') == isalpha('9'));
	assert(ft_isalpha(4) == isalpha(4));
	assert(ft_isalpha(';') == isalpha(';'));
	return (0);
}
