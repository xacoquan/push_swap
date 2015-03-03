/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 17:38:34 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/03 20:07:55 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int			ft_cases(int ac, char **av, int flags)
{
	int				var[3];
	char			error;

	error = 0;
	if (ac <= 1)
		return ((ac < 0 || (ft_atoi2(*av++, &error, flags) && error) ?
							write(1, "Error1\n", 6) : 0));
	if (((var[0] = ft_atoi2(*av++, &error, flags)) && error) ||
		((var[1] = ft_atoi2(*av++, &error, flags)) && error))
		return (write(1, "Error2\n", 6));
	if (ac == 2)
		return ((var[0] > var[1]) ? write(1, "sa\n", 3) : 0);
	if (((var[2] = ft_atoi2(*av++, &error, flags)) && error))
		return (write(1, "Error3\n", 6));
	return ((ft_order(var[0], var[1], var[2])) ? write(1, "\n", 1) : 0);
}

char	ft_pushlst(char *str, t_lst **l, int flags)
{
 	char error;
	t_lst *newp;

	error = '\0';
	if (!l)
		return (0);
	if (!(newp = (t_lst *)malloc(sizeof(t_lst))))
		return (0);
	newp->value = ft_atoi2(str, &error, flags);
	if (error)
		return (0);
	newp->next = NULL;
	if (!(*l))
		*l = newp;
	else
	{
		newp->next = *l;
		*l = newp;
	}
	return (1);
}

int		pop_element(t_lst **l_a)
{
	t_lst		*tmp;
	t_lst		*small;
	int		i;
	int		ret;

	tmp = *l_a;
	small = tmp;
	i = 0;
	ret = 0;
	while (tmp)
	{
		if (small && small->value > tmp->value)
		{
			ret = i;
			small = tmp;
		}
		i++;
		tmp = tmp->next;
	}
	tmp = *l_a;
	if (small == (*l_a))
	{
		free(*l_a);
		if (!(*l_a)->next)
			(*l_a) = NULL;
		else
			*l_a = (*l_a)->next;
	}
	while (tmp)
	{
		if (small == tmp->next)
		{
			tmp->next = small->next;
			free(small);
		}
	tmp = tmp->next;
	}
	 printf("%d\n", ret);
	return (ret);
}

void	ft_testav(int ac, char **av)
{
	char	**ptr;

	ptr = av;
	dprintf(1, "ac = [%i], av : ", ac);
    while (*ptr)
    	dprintf(1, "[\"%s]\" ", *ptr++);
    write(1, "\n", 1);
}
	
int		main(int ac, char **av)
{
	t_lst	*l_a;
	int		len;
	t_lst 	*ptr;
	int i;
	int flags;

	ft_testav(ac, av);
	flags = ft_getflags(&ac, &av);
	l_a = NULL;
	if (ac <= 1)
		return (write(1,"error\n", 6));
	len = 0;
	l_a = NULL;
//	v = 0;
	if (ac <= 4)
		return (ft_cases(ac - 1, av, flags));
	while (*av && ++len)
		if (!(ft_pushlst(*av++, &l_a, flags)))
			return (write(1, "Error\n", 6));
//		ft_testav(ac, av);
	 while (l_a)	
	 	pop_element(&l_a);
//return (0);
}
