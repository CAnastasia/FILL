/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_filling_map.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <gmadec@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 14:45:16 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 16:34:42 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_filling_map(int sizemap)
{
	char	**tab_final;
	int		i;
	int		j;

	i = -1;
	if (!(tab_final = (char**)malloc(sizeof(char*) * sizemap + 1)))
		return (NULL);
	tab_final[sizemap] = NULL;
	while (++i < sizemap)
	{
		j = 0;
		if (!(tab_final[i] = (char*)malloc(sizeof(char) * sizemap + 1)))
			return (NULL);
		while (j < sizemap)
		{
			tab_final[i][j] = '.';
			j++;
		}
		tab_final[i][j] = '\0';
	}
	return (tab_final);
}
