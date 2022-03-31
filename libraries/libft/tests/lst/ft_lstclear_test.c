/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:24:49 by pstengl           #+#    #+#             */
/*   Updated: 2022/03/31 14:54:10 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdlib.h>
#include "libft.h"

int	main(void)
{
	t_list	*lst;

	lst = NULL;
	ft_lstclear(&lst, NULL);
	ft_lstclear(&lst, free);
	lst = ft_lstnew(ft_strdup("Hello World!"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("How's it going?")));
	ft_lstclear(&lst, free);
	assert(lst == NULL);
	return (0);
}
