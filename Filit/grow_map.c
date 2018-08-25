/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   grow_map.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <gmadec@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 16:57:52 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 17:10:05 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char		**grow_map(int *size, char ***tab)
{
	free(*tab);
	*size = *size + 1;
	*tab = ft_filling_map(*size);
	return (*tab);
}

void		ft_affiche(int j, char **tab)
{
	int i;

	i = 0;
	while (i < j)
	{
		ft_putendl(tab[i]);
		i++;
	}
}
