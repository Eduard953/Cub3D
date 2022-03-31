/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:19:28 by pstengl           #+#    #+#             */
/*   Updated: 2021/06/05 17:22:14 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	ft_putnbr_fd(-12345, 1);
	ft_putnbr_fd(42, 1);
	ft_putnbr_fd(0, 1);
	ft_putnbr_fd(44, 2);
	ft_putnbr_fd(746287648, 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putnbr_fd(-897463362, 1);
	return (0);
}
