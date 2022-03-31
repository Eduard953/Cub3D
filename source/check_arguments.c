/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:56:11 by ebeiline          #+#    #+#             */
/*   Updated: 2022/03/31 17:40:42 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_format(int argc, char **argv)
{
	int len;

	if (argc < 2)
	{
		printf("too few args");
		exit(1);
	}
	if (argc > 2)
	{
		printf("too many args");
		exit(1);
	}
	len = ft_strlen(argv[1]);
	if (len < 5 || ft_strnstr(argv[1] + len - 4, ".cub", 4) == NULL)
	{
		printf("use .cub map");
		exit(1);
	}
}
