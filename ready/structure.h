/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teloise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:14:50 by teloise           #+#    #+#             */
/*   Updated: 2020/08/04 12:41:21 by teloise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct		s_map
{
	int		lines_num;
	int		col_num;
	char	empty;
	char	obstacle;
	char	full;
	char	**map;
}					t_map;

typedef struct		s_square
{
	int		x;
	int		y;
	int		len;
}					t_square;

#endif
