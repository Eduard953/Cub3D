/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttoarr_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:05:38 by pstengl           #+#    #+#             */
/*   Updated: 2022/03/31 14:56:59 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	t_list	*lst;
	char	**arr;

	lst = NULL;
	arr = NULL;
	arr = ft_lsttoarr(lst);
	assert(arr == NULL);
	ft_lstadd(&lst, "Hello World!");
	ft_lstadd(&lst, "How's it going?");
	arr = ft_lsttoarr(lst);
	assert(arr != NULL);
	assert(strcmp(arr[0], "Hello World!") == 0);
	assert(strcmp(arr[1], "How's it going?") == 0);
	assert(arr[2] == NULL);
	ft_lstclear(&lst, NULL);
	ft_arrclear(&arr, free);
	return (0);
}
