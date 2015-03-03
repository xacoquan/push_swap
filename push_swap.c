/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 17:38:34 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/03 07:25:43 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "pusw.h"
#include <stdio.h>
#include "libft/includes/libft.h"
#include <stdlib.h>
#include "push_swap.h"


void    ft_putnbr(int n)
{
	char	c;
	unsigned int num;

	if (n == -2147483648)
		write (1, "-2147483648", 11);
	if (n < 0)
	{
		ft_putchar('-');
		num = n * -1;
	}
	else
		num = n;
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		ft_putchar(num + 48);
}

int		ft_atoi2(char *str, char *error)
{
	unsigned int value;
	int max;
	char sign;

	if (!str || !*str)
		return ((*error = 1));
	value = 0;
	sign = 1;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{

		str++;
		sign = -1;
	}
	max = (sign == 1) ? 2147483647 : 2147483648;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		value = value * 10 + *str++ - '0';
		if (value > max)
			return ((*error = 1));
	}
	if (*str)
		return ((*error = 1));
	return (value * sign);
}

char	ft_pushlst(char *str, t_lst **l)
{
	char error;
	t_lst *newp;

	error = '\0';
	if (!l)
		return (0);
	if (!(newp = (t_lst *)malloc(sizeof(t_lst))))
		return (0);
	newp->value = ft_atoi2(str, &error);
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
	
int		main(int ac, char *av[])
{
	t_lst	*l_a;
	int		len;
	

	if (ac <= 1)
		return (0);
	len = 0;
	l_a = NULL;
	while (++av && *av && ++len)
		if (!(ft_pushlst(*av, &l_a)))
			return (write(1, "Error\n", 6));

	ft_sort(&l_a);
	while (len--)
		write(1, "pa ", 3);
	return (write(1, "pa\n", 3));	
}
