/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error_tetris0.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <gmadec@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 14:58:41 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 16:51:31 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error_tetris0(int ac)
{
	if (ac != 2)
	{
		if (ac > 2 || ac <= 1)
			ft_putendl("usage: ./fillit tetriminos_file");
		return (1);
	}
	return (0);
}
