/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teloise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 12:00:45 by teloise           #+#    #+#             */
/*   Updated: 2020/08/04 13:46:39 by teloise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"
#include "structure.h"

t_square	try_square(int i, int j, t_map map)
{	
	t_square	square;
	int k;
	int l;

	square.len = 0;
	square.x = i;
	square.y = j;
	while (square.len < map.col_num)
	{
		l = 0;
		square.len++;
		while (l < square.len && (j + l <= map.lines_num))
		{
			k = 0;
			while (k < square.len && (i + k < map.col_num))
			{
				if (map.map[i+k][j+l] == map.obstacle)
					return (square);
				k++;
			}
			l++;
		}
	}
	return (square);
}

t_square	map_pointing(t_map map)
{
	t_square	max_square;
	t_square	temp;
	int 		i;
	int			j;

	i = 0;
	j = 1;
	max_square.len = 0;
	max_square.x = 0;
	max_square.y = 1;
	while (j <= map.lines_num)
	{
		i = 0;
		while (i < map.col_num)
		{
			if (map.map[i][j] != map.obstacle)
			{
				temp = try_square(i, j, map);
				if (temp.len > max_square.len)
					max_square = temp;
			}
			i++;
		}
		j++;
	}
	return (max_square);
}
