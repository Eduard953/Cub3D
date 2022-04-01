/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:32:03 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/21 19:08:48 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include "libft.h"

static void	ft_rep_c(void *content)
{
	size_t	index;
	char	*temp;

	temp = (char *)content;
	index = 0;
	while (temp[index])
	{
		if (temp[index] == 'o')
			temp[index] = 'X';
		if (temp[index] == 'l')
			temp[index] = 'X';
		index++;
	}
}

static void	del(void *content)
{
	free((char *)content);
}

int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew(ft_strdup("Hello World!"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("How's it going?")));
	ft_lstiter(lst, ft_rep_c);
	assert(strcmp(lst->content, "HeXXX WXrXd!") == 0);
	assert(strcmp(lst->next->content, "HXw's it gXing?") == 0);
	ft_lstclear(&lst, del);
}
