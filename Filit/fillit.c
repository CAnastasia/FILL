/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <gmadec@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 16:30:13 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 17:17:43 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	t_list		*begin;
	char		*str_tmp;
	char		**map;
	int			sizemap;

	if (ft_error_tetris0(ac))
		return (1);
	if (!(str_tmp = ft_fcpy(av[1])))
		return (1);
	if (ft_error_tetris1(str_tmp))
		return (1);
	begin = ft_lstrsplit_fillittab(str_tmp, '\n');
	free(str_tmp);
	if (begin == NULL)
	{
		ft_putendl("error");
		return (1);
	}
	if (ft_error_tetris2(begin))
		return (1);
	sizemap = ft_sqrt_next(4 * ft_list_size(begin));
	map = ft_filling_map(sizemap);
	ft_each_tetris(&begin, map, sizemap, 0);
	return (0);
}
