/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ltabstrrpl.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <gmadec@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 14:53:05 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/31 02:41:42 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	ft_ltabstrrpl(t_list **begin, char search)
{
	int		i;
	int		j;
	int		k;
	t_list	*tmp;

	tmp = *begin;
	k = 0;
	while (tmp)
	{
		i = -1;
		while (tmp->test.pos[++i])
		{
			j = 0;
			while (tmp->test.pos[i][j])
			{
				if (tmp->test.pos[i][j] == search)
				{
					tmp->test.pos[i][j] = k + 'A';
				}
				j++;
			}
		}
		k++;
		tmp = tmp->next;
	}
}
