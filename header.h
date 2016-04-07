/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:32:05 by tbeauman          #+#    #+#             */
/*   Updated: 2015/12/03 18:06:38 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_tetri
{
	int			nb;
	t_list		*tetris;
	char		*sol;
}				t_tetri;
int				test_place (char *soluce, char *tetrimino,
		int numcase, int dim);
void			writeplace (char **soluce, t_list *tetri, int numcase, int dim);
void			eraseplace (char **soluce, t_list *tetri, int numcase, int dim);
int				solve (t_tetri soluce, t_list *tetri, int dim);
int				check_chars (char *tetriminos, size_t width);
int				check_pattern(char *tetriminos, int y, int z, size_t i);
int				check_tetriminos(t_list	*data);
int				normhelper(char *tet, int (*ij)[2],
		char *soluce, int *sharpcount);
int				check_pattern_norme_1(char *tetriminos, int y, size_t i,
		int *z);
int				check_pattern_norme_2(char *tetriminos, int z, size_t i,
		int *y);
int				mainhelper(int ac);

#endif
