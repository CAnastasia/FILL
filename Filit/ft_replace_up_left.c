/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_replace_up_left.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <gmadec@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 12:59:29 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 15:53:07 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_test_nb_tetros(t_list *tmp)
{
	int		i;
	int		j;
	int		sharp;

	sharp = 0;
	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tmp->test.pos[i][j] == '#')
				sharp++;
			j++;
		}
		i++;
	}
	return (sharp == 4 ? 0 : -1);
}

int		ft_replace_annexe(t_list **tmp, int index_h, int index_v)
{
	int		i;
	int		j;

	i = -1;
	while ((j = -1) && (*tmp)->test.pos[++i])
		while ((*tmp)->test.pos[i][++j])
		{
			if ((*tmp)->test.pos[i][j] != '.' && (*tmp)->test.pos[i][j] != '#')
				return (1);
			if ((*tmp)->test.pos[i][j] == '#' &&
			((index_h || index_v) || (index_h && index_v)))
			{
				if (index_h && !index_v)
					(*tmp)->test.pos[i][j - index_h] = '#';
				if (index_v && !index_h)
					(*tmp)->test.pos[i - index_v][j] = '#';
				if (index_v && index_h)
					(*tmp)->test.pos[i - index_v][j - index_h] = '#';
				(*tmp)->test.pos[i][j] = '.';
			}
		}
	return (ft_test_nb_tetros((*tmp)) == -1 ? 1 : 0);
}

int		ft_replace_up_left(t_list **begin)
{
	int		i;
	int		j;
	t_list	*tmp;
	int		index_h;
	int		index_v;

	tmp = *begin;
	while ((i = -1) && tmp)
	{
		index_h = -1;
		index_v = 0;
		while ((j = -1) && tmp->test.pos[++i])
			while (tmp->test.pos[i][++j])
			{
				if (tmp->test.pos[i][j] == '#' &&
				(index_h == -1 || j < index_h))
					index_h = j;
				if (j == 3 && index_h == -1)
					index_v++;
			}
		if (ft_replace_annexe(&tmp, index_h, index_v))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
