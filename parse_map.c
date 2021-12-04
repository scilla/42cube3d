/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:44:17 by scilla            #+#    #+#             */
/*   Updated: 2021/03/30 14:14:41 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	map_error(void)
{
	write(1, "Error\nmap misconfiguration", 26);
	exit(-1);
}

int		strlen_nospace(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (*str != ' ')
			len++;
		str++;
	}
	return (len);
}

char	*skip_spaces(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

int		parse_res(t_map *map, char *str)
{
	map->x_res = ft_atoi(str);
	if (!map->x_res)
		return (0);
	while (*str >= '0' && *str <= '9')
		str++;
	str = skip_spaces(str);
	map->y_res = ft_atoi(str);
	if (!map->y_res)
		return (0);
	return (1);
}

int		parse_color(char *str)
{
	int	res;

	res = 0;
	res = ft_atoi(str) * 0x10000;
	while (*str != ',' && *str)
		str++;
	str++;
	res += ft_atoi(str) * 0x100;
	while (*str != ',' && *str)
		str++;
	str++;
	res += ft_atoi(str);
	return (res);
}

int		parse_options(t_map *map, char *str)
{
	if (str[0] == 'N' && str[1] == 'O')
		map->north_path = ft_strdup(skip_spaces(&str[2]));
	else if (str[0] == 'S' && str[1] == 'O')
		map->south_path = ft_strdup(skip_spaces(&str[2]));
	else if (str[0] == 'W' && str[1] == 'E')
		map->west_path = ft_strdup(skip_spaces(&str[2]));
	else if (str[0] == 'E' && str[1] == 'A')
		map->east_path = ft_strdup(skip_spaces(&str[2]));
	else if (str[0] == 'S')
		map->sprite_path = ft_strdup(skip_spaces(&str[1]));
	else if (str[0] == 'F')
		map->floor = parse_color(skip_spaces(&str[1]));
	else if (str[0] == 'C')
		map->ceil = parse_color(skip_spaces(&str[1]));
	else if (str[0] == 'R')
		parse_res(map, skip_spaces(&str[1]));
	else
		return (0);
	/* consider bad option */
	return (1);
}

int	map_complete(t_map *map)
{
	if (map->north_path &&
	map->south_path &&
	map->west_path &&
	map->east_path &&
	map->sprite_path &&
	map->floor &&
	map->ceil)
		return (1);
	return (0);
}

void	set_cam(t_map *map, int n, int i, double rot)
{
	map->cam_x = n;
	map->cam_y = i;
	map->cam_rot = rot;
}

void	set_valid(t_map *map, int n, int i, char **lines)
{
	char	cc;

	cc = lines[i][n];
	if (lines[i][n] == '1')
		map->cells[n + i * map->max_x] = 1;
	else if (lines[i][n] == '2')
		map->cells[n + i * map->max_x] = 2;
	else if (lines[i][n] == 'E')
		set_cam(map, n, i, -M_PI / 2);
	else if (lines[i][n] == 'S')
		set_cam(map, n, i, M_PI);
	else if (lines[i][n] == 'N')
		set_cam(map, n, i, 0);
	else if (lines[i][n] == 'W')
		set_cam(map, n, i, M_PI / 2);
	else if (lines[i][n] == '0')
		map->cells[n + i * map->max_x] = 0;
	else if (lines[i][n] != ' ')
		map_error();
}

void	elab_lines(t_map *map, char **lines)
{
	int		i;
	int		n;

	i = 0;
	while (lines[i])
	{
		n = 0;
		while (lines[i][n])
		{
			set_valid(map, n, i, lines);
			n++;
		}
		i++;
	}
}

int		parse_map(int fd, t_map *map)
{
	char	**lines;
	int		res;
	int		i;
	int		n;

	i = 0;
	map->max_x = 0;
	map->max_z = 0;
	lines = malloc(sizeof(char*) * 1024);
	res = 1;
	while (res)
	{
		res = get_next_line(fd, &lines[i]);
		if (res == -1)
			map_error();
		map->max_z++;
		i++;
	}
	lines[i] = 0;
	i = -1;
	while (lines[++i])
		if ((int)ft_strlen(lines[i]) > map->max_x)
			map->max_x = ft_strlen(lines[i]);
	map->cells = malloc(sizeof(int) * map->max_x * map->max_z);
	i = 0;
	while (i < map->max_x * map->max_z)
		map->cells[i++] = -1;
	elab_lines(map, lines);
	return (1);
}

t_map	*init_map(t_data *data)
{
	t_map	*map;

	data->map = malloc(sizeof(t_map));
	map = data->map;
	map->north_path = 0;
	map->south_path = 0;
	map->west_path = 0;
	map->east_path = 0;
	map->sprite_path = 0;
	map->floor = 0;
	map->ceil = 0;
	return (map);
}

int		parse_input(t_data *data, char *filename)
{
	char	**line;
	int		fd;
	int		res;

	data->map = init_map(data);
	fd = open(filename, O_RDONLY);
	line = malloc(sizeof(char*));
	while (1)
	{
		res = get_next_line(fd, line);
		if (res == -1)
			return (0);
		if (!strlen_nospace(*line))
			continue;
		if (!parse_options(data->map, *line))
			break ;
		free(*line);
	}
	if (parse_map(fd, data->map) != 1)
		map_error();
	return (1);
}
