/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:55:11 by pstengl           #+#    #+#             */
/*   Updated: 2021/06/09 17:29:15 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

static void	print_cmp(char **dest, char **words, char *str, char del)
{
	int		index;

	index = 0;
	if (!str)
		printf("str:NULL");
	else if (ft_strlen(str) == 0)
		printf("str:''");
	else
		printf("str:'%s'", str);
	printf(", ");
	if (del == '\0')
		printf("del:'\\\\0'\n");
	else
		printf("del:'%c'\n", del);
	printf(" ft:");
	if (!dest)
		printf("NULL\n");
	else
	{
		printf("[");
		while (dest[index] != NULL)
		{
			printf("'%s', ", dest[index]);
			index++;
		}
		printf("NULL]\n");
	}
	index = 0;
	printf("ref:");
	if (!words)
		printf("NULL\n");
	else
	{
		printf("[");
		while (words[index] != NULL)
		{
			printf("'%s', ", words[index]);
			index++;
		}
		printf("NULL]\n");
	}
}

static void	ft_cmp(char *str, char del, char **words)
{
	char	**dest;
	int		index;

	dest = ft_split(str, del);
	print_cmp(dest, words, str, del);
	index = 0;
	assert((dest != NULL) == (words != NULL));
	if (dest != NULL)
	{
		while (1)
		{
			assert((dest[index] != NULL) == (words[index] != NULL));
			if (dest[index] && words[index])
				assert(strcmp(dest[index], words[index]) == 0);
			if (words[index] == NULL)
				break ;
			free(dest[index]);
			index++;
		}
		free(dest);
	}
	else
		assert(dest == words);
}

int	main(void)
{
	char		**words;

	words = ft_calloc(6, sizeof(char **));
	words[0] = "Hello";
	words[1] = "World!";
	words[2] = "this";
	words[3] = "is";
	words[4] = "great!";
	ft_cmp("Hello World! this is great!", ' ', words);
	ft_cmp("     Hello   World!   this  is great!", ' ', words);
	ft_cmp("Hello World! this is great!         ", ' ', words);
	free(words);
	words = ft_calloc(2, sizeof(char **));
	words[0] = "Hello World! this is great!";
	ft_cmp("Hello World! this is great!", 'z', words);
	ft_cmp("Hello World! this is great!", '\0', words);
	free(words);
	words = ft_calloc(2, sizeof(char *));
	words[0] = "_";
	ft_cmp("_", '\0', words);
	free(words);
	words = ft_calloc(1, sizeof(char **));
	ft_cmp("", 'z', words);
	ft_cmp("", '\0', words);
	ft_cmp("_", '_', words);
	ft_cmp("            ", ' ', words);
	free(words);
	ft_cmp(NULL, 'x', NULL);
	ft_cmp(NULL, '\0', NULL);
	return (0);
}
