/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst_bonus_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:41:41 by pstengl           #+#    #+#             */
/*   Updated: 2021/10/15 12:11:09 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "libft.h"

int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew("Hello World!");
	ft_lstadd(&lst, "How's it going?");
	ft_lstadd(&lst, "Good, how about you?");
	assert(ft_printlst(lst) == 59);
	free(lst->next->next);
	free(lst->next);
	free(lst);
	lst = NULL;
	assert(ft_printlst(lst) == 2);
}
