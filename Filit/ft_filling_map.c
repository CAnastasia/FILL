/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_filling_map.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <gmadec@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 14:45:16 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 17:15:54 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fillit.h"

char		**ft_filling_map(int sizemap)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char*) * sizemap + 1);
	while (i < sizemap)
	{
		j = 0;
		tab[i] = malloc(sizeof(char) * sizemap + 1);
		while (j < sizemap)
		{
			tab[i][j] = '.';
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	return (tab);
}
