/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstrsplit_fillittab.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <gmadec@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 20:45:00 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 21:09:20 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static	t_list	*ft_copy(char const *s, int i)
{
	t_list	*begin;
	t_list	*now;
	t_list	*after;

	if (!(begin = malloc(sizeof(t_list))))
		return (NULL);
	now = begin;
	now->test.pos = ft_strsplit(ft_strsub(s, 0, 19), '\n');
	now->next = NULL;
	i = 21;
	while (i < (int)ft_strlen(s))
	{
		if (!(after = malloc(sizeof(t_list))))
			return (NULL);
		now->next = after;
		now = after;
		now->test.pos = ft_strsplit(ft_strsub(s, i, 19), '\n');
		now->next = NULL;
		i += 21;
	}
	if (ft_replace_up_left(&begin))
		return (NULL);
	return (begin);
}

t_list			*ft_lstrsplit_fillittab(char const *s, char c)
{
	int		i;
	int		count;
	t_list	*begin;

	if (!(s))
		return (0);
	count = 0;
	i = -1;
	while (s[++i])
		s[i] != c && (s[i + 1] == c || s[i + 1] == '\0') ? count++ : 0;
	i = -1;
	begin = ft_copy(s, i);
	if (begin == NULL)
		return (NULL);
	return (begin);
}
