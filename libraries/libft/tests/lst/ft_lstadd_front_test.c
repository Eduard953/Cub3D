/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:17:46 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/21 18:54:03 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>

#include <string.h>
#include "libft.h"

int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew("Hello World!");
	ft_lstadd_front(&lst, ft_lstnew("How's it going?"));
	assert(strcmp(lst->content, "How's it going?") == 0);
	assert(strcmp(lst->next->content, "Hello World!") == 0);
	free(lst->next);
	free(lst);
	return (0);
}
