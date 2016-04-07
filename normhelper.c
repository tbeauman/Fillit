/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normhelper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:47:11 by tbeauman          #+#    #+#             */
/*   Updated: 2015/12/03 18:07:23 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		normhelper(char *tet, int (*ij)[2], char *soluce, int *sharpcount)
{
	while (tet[(*ij)[0]] != '\n' && (*ij)[0] < 19)
	{
		if (soluce[(*ij)[1]] != '.' && tet[(*ij)[0]] == '#')
			return (0);
		else
		{
			if (tet[(*ij)[0]] == '#')
				(*sharpcount)++;
			(*ij)[0]++;
			(*ij)[1] += soluce[(*ij)[1]] == '\n' ? 0 : 1;
		}
	}
	return (1);
}

int		check_pattern_norme_1(char *tetriminos, int z, size_t i, int *y)
{
	size_t	check;

	*y = 1;
	check = 2;
	if (tetriminos[i + 2] == '#')
		check++;
	if (tetriminos[i + 3] == '#')
		check++;
	if (tetriminos[i + 1] == '#' && tetriminos[i + 3] == '#'
		&& tetriminos[i + 2] != '#')
		return (0);
	if (check == 2 && z == 0 && tetriminos[i + 5] != '#')
		check--;
	return (check);
}

int		check_pattern_norme_2(char *tetriminos, int y, size_t i, int *z)
{
	size_t	check;

	*z = 1;
	check = (y == 0) ? (1) : (2);
	if (tetriminos[i - 10] == '#' || tetriminos[i + 10] == '#')
		check++;
	if (tetriminos[i - 15] == '#' || tetriminos[i + 15] == '#')
		check++;
	if ((check == 3 && y == 0)
			|| (tetriminos[i + 6] == '#' || tetriminos[i - 6] == '#'))
		check++;
	if (tetriminos[i + 9] == '#' || tetriminos[i + 16] == '#')
		check++;
	return (check);
}

int		mainhelper(int ac)
{
	if (ac != 2)
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}
