/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <gmadec@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 00:40:36 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 00:40:38 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str_return;
	size_t		j;

	j = 0;
	if (s)
	{
		if (!(str_return = (char*)malloc(sizeof(char) * len + 1)))
			return (0);
		ft_bzero(str_return, len);
		str_return[len] = '\0';
		while (j < len)
		{
			str_return[j] = s[start];
			j++;
			start++;
		}
		str_return[j] = '\0';
		return (str_return);
	}
	return (0);
}
