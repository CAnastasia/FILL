/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <gmadec@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/31 02:33:45 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 17:18:55 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../Libft/libft.h"

char					*ft_strrpl(char *str, char search, char replace);
int						ft_error_tetris0(int ac);
int						ft_error_tetris1(char *str);
int						ft_error_tetris2(t_list *tmp);
t_list					*ft_lstrsplit_fillittab(char const *s, char c);
void					ft_ltabstrrpl(t_list **begin, char search);
char					**ft_filling_map(int sizemap);
int						ft_replace_up_left(t_list **begin);
int						ft_each_tetris(t_list **begin, char **tab, int size, \
		int letter);
int						ft_check_the_same(t_list **begin);
void					ft_coord(char **tab, t_pos array[4], int ii, int jj);
char					**grow_map(int *size, char ***tab);
void					ft_affiche(int j, char **tab);

#endif
