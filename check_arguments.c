/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:56:11 by ebeiline          #+#    #+#             */
/*   Updated: 2022/03/30 17:08:37 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_format(int argc, char **argv)
{
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
	if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) == NULL)
	{
		printf("use .cub map");
		exit(1);
	}
}
