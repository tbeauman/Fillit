/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 12:06:17 by tbeauman          #+#    #+#             */
/*   Updated: 2015/12/02 18:49:58 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		test_place(char *soluce, char *t, int numcase, int dim)
{
	int		ij[2];
	int		cs;
	int		dif;
	int		sharpcount;

	ij[0] = 0;
	sharpcount = 0;
	ij[1] = numcase;
	cs = -1;
	while (ij[0] < 20 && ij[1] <= (dim + 1) * dim)
	{
		while (ij[0] % 5 != cs && (t[ij[0]] == '.' || t[ij[0]] == '\n'))
			ij[0]++;
		if (cs == -1)
			cs = ij[0] % 5;
		dif = cs - ij[0] % 5;
		ij[1] -= dif;
		if (!normhelper(t, &ij, soluce, &sharpcount))
			return (0);
		while (ij[1] % (dim + 1) != numcase % (dim + 1))
			ij[1]++;
	}
	if (sharpcount != 4)
		return (0);
	return (1);
}

void	writeplace(char **soluce, t_list *t, int numcase, int dim)
{
	int		ij[3];
	int		colspot;

	ij[0] = 0;
	ij[1] = numcase;
	colspot = -1;
	while (ij[0] < 19 && ij[1] < (dim + 1) * dim)
	{
		while (ij[0] % 5 != colspot && t->content[ij[0]] != '#'
				&& (t->content[ij[0]] == '.' || t->content[ij[0]] == '\n'))
			ij[0]++;
		if (colspot == -1)
			colspot = ij[0] % 5;
		ij[2] = colspot - ij[0] % 5;
		ij[1] -= ij[2];
		while (t->content[ij[0]] != '\n')
		{
			if (t->content[ij[0]] == '#')
				(*soluce)[ij[1]] = 'A' + t->index;
			ij[1] += (*soluce)[ij[1]] == '\n' ? 0 : 1;
			ij[0]++;
		}
		while (ij[1] % (dim + 1) != numcase % (dim + 1))
			ij[1]++;
	}
}

void	eraseplace(char **soluce, t_list *t, int numcase, int dim)
{
	int		ij[3];
	int		colspot;

	ij[0] = 0;
	ij[1] = numcase;
	colspot = -1;
	while (ij[0] < 19)
	{
		while (ij[0] % 5 != colspot && t->content[ij[0]] != '#'
				&& (t->content[ij[0]] == '.' || t->content[ij[0]] == '\n'))
			ij[0]++;
		if (colspot == -1)
			colspot = ij[0] % 5;
		ij[2] = colspot - ij[0] % 5;
		ij[1] -= ij[2];
		while (t->content[ij[0]] != '\n')
		{
			if (t->content[ij[0]] == '#')
				(*soluce)[ij[1]] = '.';
			ij[1] += (*soluce)[ij[1]] == '\n' ? 0 : 1;
			ij[0]++;
		}
		while (ij[1] % (dim + 1) != numcase % (dim + 1))
			ij[1]++;
	}
}

int		allplaced(t_list *tetri)
{
	while (tetri)
	{
		if (tetri->content_size == 0)
			return (0);
		tetri = tetri->next;
	}
	return (1);
}

int		solve(t_tetri stru, t_list *tetri, int dim)
{
	int		numcase;

	numcase = 0;
	if (allplaced(stru.tetris))
		return (1);
	while (numcase < (dim + 1) * dim)
	{
		if (test_place(stru.sol, tetri->content, numcase, dim))
		{
			writeplace(&(stru.sol), tetri, numcase, dim);
			tetri->content_size = 1;
			if (solve(stru, tetri->next, dim))
				return (1);
			eraseplace(&(stru.sol), tetri, numcase, dim);
			tetri->content_size = 0;
		}
		numcase++;
	}
	return (0);
}
