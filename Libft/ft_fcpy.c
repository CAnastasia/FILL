/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fcpy.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <gmadec@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 17:46:38 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 17:46:50 by gmadec      ###    #+. /#+    ###.fr     */
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
	int		i;
	int		ret;
	char	buf[BUF_SIZE + 1];

	ret = 0;
	i = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
	{
		ft_putendl("error");
		return (NULL);
	}
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strdup(buf);
		i++;
	}
	if (close(fd) == -1 || !tmp || ret == -1 || (i == 0 && ret <= 0))
	{
		ft_putendl("error");
		return (NULL);
	}
	return (tmp);
}
