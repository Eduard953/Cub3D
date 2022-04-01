/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace_bonus_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:38:21 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/21 22:40:33 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "libft.h"

int	main(void)
{
	assert(ft_isspace(' ') == 1);
	assert(ft_isspace('\t') == 1);
	assert(ft_isspace('\n') == 1);
	assert(ft_isspace('\v') == 1);
	assert(ft_isspace('\f') == 1);
	assert(ft_isspace('\r') == 1);
	assert(ft_isspace('X') == 0);
	assert(ft_isspace(0) == 0);
}
