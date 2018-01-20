/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fcpy.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <gmadec@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 15:19:01 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/03 23:01:45 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

#define BUF_SIZE 650

char		*ft_fcpy(char *av)
{
	char	*tmp;
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	ret = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
	{
		ft_putendl("error");
		return (NULL);
	}
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = ft_strdup(buf);
	}
	if (close(fd) == -1 || !tmp)
	{
		ft_putendl("error");
		return (NULL);
	}
	return (tmp);
}
