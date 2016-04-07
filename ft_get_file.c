/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:31:32 by tbeauman          #+#    #+#             */
/*   Updated: 2015/12/03 18:06:20 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*save_file(char *filename)
{
	int		fd;
	int		rdvalu;
	char	*buf;
	t_list	*ret;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buf = (char*)malloc(21);
	if (!buf)
		return (NULL);
	ret = NULL;
	while ((rdvalu = read(fd, buf, 21)))
	{
		buf[rdvalu] = '\0';
		ft_lstadd(&ret, ft_lstnew(buf, 21));
	}
	close(fd);
	return (ret);
}

void	adjust_list(t_list **file)
{
	t_list	*test;
	int		i;

	i = 0;
	test = *file;
	while (test)
	{
		if (test->next)
			ft_memcpy(test->content + 20, "\0", 1);
		else
		{
			if (ft_strlen(test->content) != 20)
			{
				ft_putstr("error\n");
				exit(EXIT_FAILURE);
			}
			ft_memcpy(test->content + 19, "\n\0", 2);
		}
		test->content_size = 0;
		test->index = i;
		i++;
		test = test->next;
	}
}

int		get_mindims(t_list *tetris)
{
	int		i;
	int		ret;

	i = ft_lstlen(tetris) * 4;
	ret = 0;
	while (ret * ret < i)
		ret++;
	return (ret);
}

t_tetri	initstruc(t_list *tetris, int soldim)
{
	t_tetri	ret;
	int		i;

	i = 1;
	ret.nb = ft_lstlen(tetris);
	ret.tetris = tetris;
	ret.sol = (char*)malloc(((soldim + 1) * soldim + 1) * sizeof(char));
	while (i < (soldim + 1) * soldim + 1)
	{
		if (i % (soldim + 1))
			ret.sol[i - 1] = '.';
		else
			ret.sol[i - 1] = '\n';
		i++;
	}
	ret.sol[i] = '\0';
	return (ret);
}

int		main(int ac, char **av)
{
	t_list	*test;
	t_tetri	stru;
	int		dim;

	if (mainhelper(ac))
		return (1);
	test = save_file(av[1]);
	adjust_list(&test);
	if (check_tetriminos(test) == 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	dim = get_mindims(test);
	stru = initstruc(test, dim);
	while (!solve(stru, test, dim))
	{
		dim++;
		free(stru.sol);
		stru.sol = NULL;
		stru = initstruc(test, dim);
	}
	ft_putstr(stru.sol);
	return (0);
}
