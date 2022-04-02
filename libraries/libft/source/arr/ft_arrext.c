/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:46:31 by pstengl           #+#    #+#             */
/*   Updated: 2022/04/02 15:53:47 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_arrext(char ***arr, void *content)
{
	size_t	i;
	char	**new_arr;

	if (content == NULL)
		return ;
	new_arr = ft_calloc(ft_arrlen(*arr) + 2, sizeof(void *));
	i = 0;
	if (*arr)
	{
		while ((*arr)[i])
		{
			new_arr[i] = (*arr)[i];
			i++;
		}
	}
	new_arr[i] = content;
	free(*arr);
	*arr = new_arr;
}
