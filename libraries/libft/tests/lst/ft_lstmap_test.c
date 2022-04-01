/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:48:49 by pstengl           #+#    #+#             */
/*   Updated: 2021/06/04 16:55:52 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>

#include "libft.h"

static void	*ft_repl_c(void	*content)
{
	size_t	index;

	index = 0;
	while (((char *)content)[index])
	{
		if (((char *)content)[index] == 'o')
			((char *)content)[index] = 'X';
		if (((char *)content)[index] == 'l')
			((char *)content)[index] = 'X';
		index++;
	}
	return (((char *)content));
}

static void	ft_del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*lst;
	t_list	*dest;

	assert(ft_lstmap(NULL, ft_repl_c, ft_del) == NULL);
	lst = ft_lstnew(ft_strdup("Hello World!"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("How's it going?")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("I'm fine...")));
	assert(ft_lstmap(lst, ft_repl_c, NULL) == NULL);
	dest = ft_lstmap(lst, &ft_repl_c, &ft_del);
	assert(ft_lstmap(lst, NULL, ft_del) == NULL);
	assert(lst != dest);
	assert(strcmp(dest->content, "HeXXX WXrXd!") == 0);
	assert(strcmp(dest->next->content, "HXw's it gXing?") == 0);
	assert(ft_lstmap(NULL, &ft_repl_c, &ft_del) == NULL);
	assert(ft_lstmap(lst, NULL, &ft_del) == NULL);
	assert(ft_lstmap(lst, &ft_repl_c, NULL) == NULL);
	ft_lstclear(&lst, ft_del);
	free(dest->next->next);
	free(dest->next);
	free(dest);
	return (0);
}
