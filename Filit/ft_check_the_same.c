/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_checkTheSame.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <gmadec@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 19:56:17 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 16:05:10 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_the_same(t_list **begin)
{
	t_list		*tmp;
	t_pos		array1[4];
	t_pos		array2[4];
	int			i;
	int			j;

	tmp = *begin;
	i = 0;
	j = 0;
	while (tmp->next)
	{
		ft_coord(tmp->test.pos, array1, 0, 0);
		ft_coord(tmp->next->test.pos, array2, 0, 0);
		while (i < 4)
		{
			if (array1[i].x == array2[i].x && array1[i].y == array2[i].y)
				j++;
			i++;
		}
		tmp = tmp->next;
	}
	if (j == 4 * ft_list_size(tmp))
		return (1);
	return (0);
}
