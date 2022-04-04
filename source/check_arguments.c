/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:56:11 by ebeiline          #+#    #+#             */
/*   Updated: 2022/04/04 19:22:22 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_format(int argc, char **argv)
{
	int	len;

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

void	check_map(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->map.size.y)
	{
		j = 0;
		while (j < data->map.size.x)
		{
			if (ft_strchr("012NSEW ", data->map.tiles[i][j]) == NULL)
				error_message("invalid map");
			j++;
		}
		i++;
	}
}
