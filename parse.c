/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:56:11 by ebeiline          #+#    #+#             */
/*   Updated: 2022/03/30 15:58:51 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_format(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "too few args", 13);
		exit(-1);
	}
	if (argc > 2)
	{
		write(1, "too many args", 14);
		exit(-1);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		write(1, "use .ber map", 13);
		exit(-1);
	}
}

void	get_map(t_vars *vars, char **argv)
{
	int		row;
	int		fd;

	row = 0;
	vars->map.mtx = malloc((vars->map.size.y + 1) * sizeof(char *));
	vars->map.mtx[vars->map.size.y] = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "map not found", 14);
		exit(-1);
	}
	while (get_next_line(fd, &vars->map.mtx[row]))
		row++;
	close(fd);
	checkmap(vars);
}