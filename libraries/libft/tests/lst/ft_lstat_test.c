/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat_bonus_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:13:53 by pstengl           #+#    #+#             */
/*   Updated: 2021/10/11 11:04:33 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew("Hello World!");
	ft_lstadd(&lst, "How's it going?");
	ft_lstadd(&lst, "Good, how about you?");
	assert(strcmp(ft_lstat(lst, 2)->content, "Good, how about you?") == 0);
	assert(lst == ft_lstat(lst, 0));
	assert(lst->next == ft_lstat(lst, 1));
	assert(lst->next->next == ft_lstat(lst, 2));
	assert(lst->next->next == ft_lstat(lst, -1));
	assert(lst->next == ft_lstat(lst, -2));
	assert(ft_lstat(lst, 12) == NULL);
	free(lst->next->next);
	free(lst->next);
	free(lst);
	return (0);
}
