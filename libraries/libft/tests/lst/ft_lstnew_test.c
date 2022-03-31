/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:12:13 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/21 18:53:15 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew("Hello World!");
	assert(lst->next == NULL);
	assert(strcmp(lst->content, "Hello World!") == 0);
	free(lst);
	return (0);
}
