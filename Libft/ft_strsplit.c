/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <gmadec@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 00:40:11 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 16:38:45 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**ft_attrib_word(char **tab, char const *s, int i, char c)
{
	int		count;
	int		index;

	index = 0;
	while (s[++i])
	{
		count = 0;
		while (s[i + count] != c && s[i + count])
			count++;
		if (count > 0)
		{
			if (!(tab[index] = (char*)malloc(sizeof(char) * count + 1)))
				return (0);
			tab[index] = ft_strsub(s, i, count);
			index++;
			i = i + count - 1;
		}
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		count;

	if (!(s))
		return (0);
	count = 0;
	i = -1;
	while (s[++i])
		s[i] != c && (s[i + 1] == c || s[i + 1] == '\0') ? count++ : 0;
	if (!(tab = (char**)malloc(sizeof(char*) * count + 1)))
		return (0);
	tab[count] = NULL;
	i = -1;
	if (!(tab = ft_attrib_word(tab, s, i, c)))
		return (0);
	return (tab);
}
