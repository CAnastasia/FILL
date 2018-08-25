/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error_tetris2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <gmadec@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 14:39:15 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 20:53:34 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static	int	ft_error_tetris2_annexe(t_list *tmp, int i, int j, int count)
{
	while (tmp->test.pos[++i])
	{
		j = -1;
		while (tmp->test.pos[i][++j])
		{
			if (tmp->test.pos[i][j] != '.' && tmp->test.pos[i][j] != '#')
				return (1);
			if (j != 0 && tmp->test.pos[i][j] == tmp->test.pos[i][j - 1] &&
					tmp->test.pos[i][j] == '#')
				count++;
			if (j != 3 && tmp->test.pos[i][j] == tmp->test.pos[i][j + 1] &&
					tmp->test.pos[i][j] == '#')
				count++;
			if (i != 3 && tmp->test.pos[i + 1][j] == tmp->test.pos[i][j] &&
					tmp->test.pos[i][j] == '#')
				count++;
			if (i != 0 && tmp->test.pos[i - 1][j] == tmp->test.pos[i][j] &&
					tmp->test.pos[i][j] == '#')
				count++;
		}
		if (i != 0 && ((i + 1) % 4) == 0 && (count != 6 && count != 8))
			return (1);
	}
	return (0);
}

int			ft_error_tetris2(t_list *tmp)
{
	int		i;
	int		j;
	int		count;

	j = 0;
	if (ft_list_size(tmp) == 0 || ft_list_size(tmp) > 26)
	{
		ft_putendl("error");
		return (1);
	}
	while (tmp)
	{
		i = -1;
		count = 0;
		if (ft_error_tetris2_annexe(tmp, i, j, count) == 1)
		{
			ft_putendl("error");
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
