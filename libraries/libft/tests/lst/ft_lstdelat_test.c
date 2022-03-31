/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelat_bonus_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:35:10 by pstengl           #+#    #+#             */
/*   Updated: 2021/10/11 11:56:16 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "libft.h"

static void	ft_del_str(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew(ft_strdup("Hello World!"));
	ft_lstadd(&lst, ft_strdup("How's it going"));
	ft_lstadd(&lst, ft_strdup("Good how are you"));
	assert(ft_strcmp(ft_lstat(lst, 1)->content, "How's it going") == 0);
	ft_lstdelat(&lst, 1, ft_del_str);
	assert(ft_lstat(lst, 0) != NULL);
	assert(ft_lstat(lst, 1) != NULL);
	assert(ft_lstat(lst, 2) == NULL);
	assert(ft_strcmp(ft_lstat(lst, 1)->content, "Good how are you") == 0);
	ft_lstdelat(&lst, 0, ft_del_str);
	assert(ft_strcmp(ft_lstat(lst, 0)->content, "Good how are you") == 0);
	assert(ft_lstat(lst, 0) != NULL);
	assert(ft_lstat(lst, 1) == NULL);
	ft_lstdelat(&lst, 0, ft_del_str);
	assert(lst == NULL);
	return (0);
}
