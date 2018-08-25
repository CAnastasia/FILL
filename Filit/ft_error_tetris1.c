/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error_tetris1.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <gmadec@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 15:07:12 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 21:14:43 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error_tetris1(char *str)
{
	int		i;
	int		j;
	int		error;

	error = 0;
	i = -1;
	j = -1;
	while (str[++i])
	{
		if (((i + 1) % 21) == 0 && str[i] != '\n' && i > 0)
			error = 1;
		if ((str[i] != '.' && str[i] != '#' && (i + 1) % 21 != 0) &&
		j % 4 && str[i] != '\n')
			error = 1;
		if (i % 21 != 0)
			j++;
	}
	if ((i + 1) % 21 != 0 || error == 1)
	{
		ft_putendl("error");
		return (1);
	}
	return (0);
}
