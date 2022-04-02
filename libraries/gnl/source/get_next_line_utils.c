/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 19:56:21 by pstengl           #+#    #+#             */
/*   Updated: 2021/06/14 17:42:06 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	gnl_bzero(void	*space, size_t size)
{
	size_t	counter;

	counter = 0;
	while (counter < size)
	{
		((unsigned char *)space)[counter] = '\0';
		counter++;
	}
}

void	*gnl_calloc(size_t nmemb, size_t size)
{
	size_t	final_size;
	void	*space;

	final_size = nmemb * size;
	if (final_size != 0)
		if (final_size / nmemb != size)
			return (NULL);
	space = malloc(final_size);
	if (space == NULL)
		return (NULL);
	gnl_bzero(space, final_size);
	return (space);
}

size_t	gnl_strlen(char	*str)
{
	size_t	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*gnl_strext(char **base, char *ext, size_t size)
{
	char	*temp;
	size_t	count;
	size_t	base_len;

	base_len = gnl_strlen(*base);
	if (gnl_strlen(ext) < size)
		size = gnl_strlen(ext);
	temp = gnl_calloc(sizeof(char *), base_len + size + 1);
	if (temp == NULL)
		return (NULL);
	count = 0;
	while (*base && (*base)[count])
	{
		temp[count] = (*base)[count];
		count++;
	}
	free(*base);
	count = 0;
	while (ext[count] && count < size)
	{
		temp[count + base_len] = ext[count];
		count++;
	}
	*base = temp;
	return (temp);
}

void	gnl_prune_front(void *space, size_t from, size_t max_size)
{
	size_t	count;

	count = 0;
	while ((from + count) < max_size)
	{
		((char *)space)[count] = ((char *)space)[from + count];
		count++;
	}
	while (count < max_size)
	{
		((char *)space)[count] = '\0';
		count++;
	}
}
