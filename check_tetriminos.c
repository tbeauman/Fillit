/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rortega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 15:23:21 by rortega           #+#    #+#             */
/*   Updated: 2015/12/03 16:23:53 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				check_chars(char *tetriminos, size_t width)
{
	size_t	i;
	size_t	n;
	size_t	d;

	i = 0;
	n = 0;
	d = 0;
	while (tetriminos[i])
	{
		if ((tetriminos[i] != '.' && tetriminos[i] != '#'
					&& tetriminos[i] != '\n') || width > 5)
			return (0);
		if (tetriminos[i] == '\n')
		{
			width = 0;
			n++;
		}
		if (tetriminos[i] == '#')
			d++;
		i++;
		width++;
	}
	if (ft_strlen(tetriminos) != 20)
		return (0);
	return ((d != 4 || n != 4) ? 0 : 1);
}

int				check_pattern(char *tetriminos, int y, int z, size_t i)
{
	size_t	check;
	size_t	nb_chars;

	nb_chars = 0;
	check = 0;
	while (tetriminos[i])
	{
		if (tetriminos[i] == '#')
		{
			nb_chars = 0;
			if (tetriminos[i + 1] == '#' && y == 0)
				check += check_pattern_norme_1(tetriminos, z, i, &y);
			else if ((tetriminos[i - 5] == '#' || tetriminos[i + 5] == '#')
					&& z == 0)
				check += check_pattern_norme_2(tetriminos, y, i, &z);
		}
		if (nb_chars > 6 && check <= 3 && check)
			return (0);
		nb_chars++;
		i++;
	}
	return ((check >= 4) ? 1 : 0);
}

int				check_tetriminos(t_list *data)
{
	char	*s;
	size_t	i;

	i = 0;
	if (!data)
		return (0);
	while (data)
	{
		s = data->content;
		if (check_chars(s, 0) == 0 || check_pattern(s, 0, 0, 0) == 0)
			return (0);
		if (i > 26)
			return (0);
		data = data->next;
		i++;
	}
	return (1);
}
