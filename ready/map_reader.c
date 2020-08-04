/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teloise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:26:30 by teloise           #+#    #+#             */
/*   Updated: 2020/08/04 14:26:17 by teloise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "functions.h"
#include "square.h"

#define BUF_SIZE 4096

void	nulling_map(t_map *map)
{
	map->map = ((void *)0);
	map->lines_num = 0;
	map->col_num = 0;
	map->empty = 0;
	map->obstacle = 0;
	map->full = 0;
}

void	filling_map(t_map *map, int fd)
{
	int		i;
	int		j;
	char	*tmp;
	char	c[1];

	j = 0;
	while (read(fd, c, 1))
	{
		i = 0;
		if (!(tmp = malloc(sizeof(char) * 1024)))
			return ;
		while (c[0] != '\n')
		{
			tmp[i] = c[0];
			read(fd, c, 1);
			i++;
		}
		map->map[j] = ft_strdup(tmp);
		j++;
	}
	map->col_num = j - 1;
	map->lines_num = map->map[0][0] - 48;
	map->empty = map->map[0][1];
	map->obstacle = map->map[0][2];
	map->full = map->map[0][3];
}

int		check_file(char *name)
{
	int fd;

	if (name)
		fd = open(name, O_RDONLY);
	else
		return (0);
	if (fd == -1)
		return (0);
	return (fd);
}

t_map	read_file(char *name)
{
	int		fd;
	t_map	map;

	nulling_map(&map);
	fd = check_file(name);
	if (fd == 0)
		return (map);
	if (!(map.map = (char **)malloc(sizeof(map) * (BUF_SIZE + 1))))
		return (map);
	filling_map(&map, fd);
	close(fd);
	return (map);
}

int		main(void)
{
	t_map	map;
	t_square max;

	map = read_file("map.txt");
	print_tab(map.map, map.col_num + 1);
	max = map_pointing(map);
	ft_putchar(max.x + 48);
	ft_putchar(max.y + 48);
	ft_putchar(max.len + 48);
}
