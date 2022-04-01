/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarr_bonus_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:01:56 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/21 20:16:06 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	char	**arr;

	arr = ft_split("Hello World, this is great!", ' ');
	ft_printarr(arr);
	while (*arr != NULL)
	{
		free(*arr);
		arr++;
	}
	free(arr - 5);
	return (0);
}
