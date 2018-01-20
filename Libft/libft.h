/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <gmadec@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 00:41:56 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 15:50:12 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>

typedef	struct			s_fillit
{
	char				**pos;
}						t_fillit;

typedef	struct			s_strlist
{
	char				*str;
	struct s_strlist	*next;
}						t_strlist;

typedef	struct			s_pos
{
	int					x;
	int					y;
}						t_pos;

typedef	struct			s_list
{
	void				*content;
	size_t				content_size;
	t_fillit			test;
	t_strlist			str_lst;
	t_pos				pos;
	struct s_list		*next;
	char				letter;
}						t_list;

char					*ft_strdup(const char *s);
size_t					ft_strlen(const char *str);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_bzero(void *s, size_t n);
void					ft_putendl(char const *s);
char					**ft_strsplit(char const *s, char c);
void					ft_puttabstr(char **str);
char					*ft_strsub(char const *s, unsigned int start, \
		size_t len);
int						ft_list_size(t_list *begin_list);
char					*ft_fcpy(char *av);
int						ft_sqrt_next(int nb);

#endif
