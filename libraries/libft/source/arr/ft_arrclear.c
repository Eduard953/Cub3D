/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:58:57 by pstengl           #+#    #+#             */
/*   Updated: 2022/03/31 15:26:02 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_arrclear(char ***arr, void (*f)(void *content))
{
	int	index;

	if (!arr)
		return ;
	if (!(*arr))
		return ;
	if (f)
	{
		index = 0;
		while ((*arr)[index])
		{
			if (f)
				f((*arr)[index]);
			(*arr)[index] = NULL;
			index++;
		}
	}
	free(*arr);
	*arr = NULL;
}
