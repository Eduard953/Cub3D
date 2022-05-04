/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:27:58 by ebeiline          #+#    #+#             */
/*   Updated: 2022/05/04 20:44:49 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color(char **line)
{
	int	color;

	color = ft_atoi(*line);
	if (color < 0 || color > 255)
		error_message("color out of rgb range");
	while (ft_isdigit(**line))
		(*line)++;
	(*line)++;
	return (color);
}

t_texture	parse_texture(char *line)
{
	t_texture	tex;
	char		*filename;
	int			len;

	filename = ft_strtrim(line, " ");
	len = ft_strlen(filename);
	if (len < 5 || ft_strnstr(filename + len - 4, ".xpm", 4) == NULL)
		error_message("use .xpm filename");
	tex.filename = filename;
	return (tex);
}

int	parse_color(char *line)
{
	int	color;
	int	r;
	int	g;
	int	b;

	while (*line == ' ')
		line++;
	r = get_color(&line);
	g = get_color(&line);
	b = get_color(&line);
	color = (r << 16) + (g << 8) + b;
	return (color);
}

int	parse_line(t_data *data, char *line, int fd)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return (1);
	if (line[i] == 'N' && line[i + 1] == 'O')
		data->map.texture_north = parse_texture(line + i + 2);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		data->map.texture_south = parse_texture(line + i + 2);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		data->map.texture_east = parse_texture(line + i + 2);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		data->map.texture_west = parse_texture(line + i + 2);
	else if (line[i] == 'F')
		data->map.floor_color = parse_color(line + i + 1);
	else if (line[i] == 'C')
		data->map.ceiling_color = parse_color(line + i + 1);
	else
		return (get_x_y(data, line, fd));
	data->map.skip++;
	return (1);
}
