/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <gmadec@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 00:39:38 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/14 11:30:57 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char		*str_return;
	size_t		i;

	i = 0;
	if (!(str_return = (char*)malloc(sizeof(char) * size + 1)))
		return (0);
	while (i <= size)
	{
		str_return[i] = '\0';
		i++;
	}
	return (str_return);
}
