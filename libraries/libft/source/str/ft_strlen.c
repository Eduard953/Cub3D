/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:22:49 by pstengl           #+#    #+#             */
/*   Updated: 2022/04/02 14:11:37 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	if (!s)
		return (length);
	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}
