/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 17:38:34 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/03 18:00:30 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# define HELP 0b00000001
# define VISUAL 0b00000010
# define COLOR 0b00000100
# define OVERFLOW 0b00001000
# define DOUBLES 0b00010000

typedef struct		s_lst
{
	int				value;
	struct s_lst	*next;
}					t_lst;
#endif

static int			ft_cases(int ac, char **av, int flags);
char	ft_pushlst(char *str, t_lst **l, int flags);
int		pop_element(t_lst **l_a);
void    ft_putnbr(int n);
int		ft_atoi2(const char *str, char *error, int flags);
void	ft_putchar(char c);
int		ft_order(int a, int b, int c);
int     ft_getflags(int *ac, char ***av);
int     ft_strncmp(char *a, char *b);

