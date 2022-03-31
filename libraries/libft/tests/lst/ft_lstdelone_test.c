/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:06:45 by pstengl           #+#    #+#             */
/*   Updated: 2021/05/21 21:46:59 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>

#include "libft.h"

static void	del(void *content)
{
	free((char *)content);
}

int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew(ft_strdup("Hello World!"));
	ft_lstdelone(lst, del);
	return (0);
}
