/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:31:08 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/21 18:54:40 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "libft.h"

int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew("Hello World!");
	assert(ft_lstsize(lst) == 1);
	ft_lstadd_front(&lst, ft_lstnew("How's it going?"));
	assert(ft_lstsize(lst) == 2);
	free(lst->next);
	free(lst);
	return (0);
}
