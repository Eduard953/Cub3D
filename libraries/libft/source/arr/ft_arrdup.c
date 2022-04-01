/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:06:03 by pstengl           #+#    #+#             */
/*   Updated: 2022/04/01 14:34:33 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrdup(char **in_arr)
{
	char	**new_arr;
	int		index;

	if (!in_arr)
		return (NULL);
	new_arr = ft_calloc(ft_arrlen(in_arr) + 1, sizeof(char *));
	index = 0;
	while (in_arr[index])
	{
		new_arr[index] = ft_strdup(in_arr[index]);
		index++;
	}
	return (new_arr);
}
