/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:01:12 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/25 15:11:29 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew("Hello World!");
	ft_lstadd_back(&lst, ft_lstnew("How's it going?"));
	assert(strcmp(lst->content, "Hello World!") == 0);
	assert(strcmp((lst->next)->content, "How's it going?") == 0);
	free(lst->next);
	free(lst);
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew("Hello World!"));
	assert(lst != NULL);
	assert(strcmp(lst->content, "Hello World!") == 0);
	free(lst);
	return (0);
}
