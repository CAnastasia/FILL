/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_coord.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <gmadec@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/31 00:34:25 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 17:13:17 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

#define CHECK(v) (*tab)[i + array[v].x][j + array[v].y] == '.'

void	ft_coord(char **tab, t_pos array[4], int ii, int jj)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == '#')
			{
				array[k].x = i + ii;
				array[k].y = j + jj;
				k++;
			}
			j++;
		}
		i++;
	}
}

int		check_letter(char ***tab, t_list *tmp, int t[4])
{
	int			i;
	int			j;
	t_pos		array[4];

	i = -1;
	ft_coord(tmp->test.pos, array, t[0], t[1]);
	while (array[0].x + (++i) < t[2] && array[1].x + i < t[2]
			&& array[2].x + i < t[2] && array[3].x + i < t[2])
	{
		j = 0;
		while (array[0].y + j < t[2] && array[1].y + j < t[2]
				&& array[2].y + j < t[2] && array[3].y + j < t[2])
		{
			if (CHECK(0) && CHECK(1) && CHECK(2) && CHECK(3))
			{
				(*tab)[i + array[0].x][j + array[0].y] = t[3] + 'A';
				(*tab)[i + array[1].x][j + array[1].y] = t[3] + 'A';
				(*tab)[i + array[2].x][j + array[2].y] = t[3] + 'A';
				(*tab)[i + array[3].x][j + array[3].y] = t[3] + 'A';
				return (0);
			}
			j++;
		}
	}
	return (1);
}

void	delete_letter(char **tab, int letter, int size)
{
	int			i;
	int			j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i][j] == letter + 'A')
				tab[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		ft_each_tetris_annexe(int t[4], t_list *tmp, char ***tab, int *y)
{
	while (t[0] * t[1] < t[2] * t[2])
	{
		if (*y == 0)
		{
			if (!(check_letter(&(*tab), tmp, t)))
			{
				*y = ft_each_tetris(&tmp->next, *tab, t[2], ++t[3]);
				t[3]--;
			}
			else
			{
				if (t[0] * t[1] == t[2] * t[2] - t[2] ||
				ft_check_the_same(&tmp))
				{
					delete_letter(*tab, --t[3], t[2]);
					if (t[3] != -1)
						return (0);
					t[3]++;
				}
			}
		}
		t[1] < t[2] ? t[0] = t[0] : t[0]++;
		t[1] < t[2] ? t[1]++ : (t[1] = 0);
	}
	return (1);
}

int		ft_each_tetris(t_list **begin, char **tab, int size, int letter)
{
	t_list		*tmp;
	int			y;
	int			t[4];

	tmp = *begin;
	y = 0;
	t[0] = 0;
	t[1] = 0;
	t[2] = size;
	t[3] = letter;
	if (tmp)
	{
		if (ft_list_size(tmp) == 9 && !ft_check_the_same(&tmp) && t[3] == 0)
			tab = grow_map(&t[2], &tab);
		if (!(ft_each_tetris_annexe(t, tmp, &tab, &y)))
			return (0);
		if (y == 0)
		{
			tab = grow_map(&t[2], &tab);
			ft_each_tetris(&tmp, tab, t[2], 0);
		}
	}
	else
		ft_affiche(t[2], tab);
	return (1);
}
