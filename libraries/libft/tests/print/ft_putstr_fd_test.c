/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:19:28 by pstengl           #+#    #+#             */
/*   Updated: 2021/06/05 17:30:39 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	ft_putstr_fd("Look!", 1);
	ft_putstr_fd(NULL, 1);
	ft_putstr_fd("", 1);
	ft_putstr_fd("ERROR", 2);
	ft_putstr_fd("This\nis\ngreat!\n", 1);
	return (0);
}
