/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_replace_up_left.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <gmadec@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 12:59:29 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 21:07:31 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_replace_annexe(t_list **tmp, int index_h, int index_v)
{
	int		i;
	int		j;

	i = -1;
	while ((*tmp)->test.pos[++i])
	{
		j = -1;
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
	}
	return (0);
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
