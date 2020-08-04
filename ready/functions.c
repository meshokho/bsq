/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teloise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:14:45 by teloise           #+#    #+#             */
/*   Updated: 2020/08/03 17:30:37 by teloise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int j;

	j = 0;
	while (str[j] != '\0')
	{
		write(1, &str[j], 1);
		j++;
	}
	ft_putchar('\n');
}

char	*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*copy;

	i = 0;
	size = 0;
	while (src[size])
		size++;
	if (!(copy = (char*)malloc(size + 1)))
		return (NULL);
	while (i < size)
	{
		copy[i] = src[i];
		i++;
	}
	copy[size] = '\0';
	return (copy);
	free(copy);
}

void	print_tab(char **tab, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		ft_putstr(tab[j]);
		j++;
	}
}
