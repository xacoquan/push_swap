/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pstools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 08:36:02 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/03 18:26:11 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


int 	ft_strncmp(char *a, char *b)
{
    while (*a && *a == *b)
    {
        a++;
        b++;
    }
    return (!*a);
}

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

int                     ft_atoi2(const char *str, char *error, int flags)
{
    static unsigned int value;
    static unsigned int max;
    static int          sign;

    if (!str)
        return ((*error = 1));
    sign = 1;
    if (*str == '+')
        str++;
    else if (*str == '-' && str++)
        sign = -1;
    max = (sign == 1) ? 2147483647 : 2147483648;
    if (!(*str >= '0' && *str <= '9'))
        return ((*error = 1));
    value = 0;
    while (*str && (*str >= '0' && *str <= '9'))
        if ((value = value * 10 + *str++ - '0') > max)
            return ((*error = 1));
    // if (*str)
    //     return ((*error = 1));	
    return (value * sign);
}

int                 ft_getflags(int *ac, char ***av)
{
    int             flags;

    if (!av || !*av || !**av)
    {
        write(1, "Error\n", 6);
        return (-1);
    }
    (*av)++;
    flags = 0;
    while (**av)
    {
        if (ft_strncmp("-help", **av))
            flags |= HELP;
        else if (ft_strncmp("-visual", **av))
            flags |= VISUAL;
        else if (ft_strncmp("-color", **av))
            flags |= COLOR;
        else if (ft_strncmp("-overflow", **av))
            flags |= OVERFLOW;
	else if (ft_strncmp("-doubles", **av))
            flags |= DOUBLES;
        else
            return (flags);
        (*av)++;
        (*ac)--;
    }
    return (flags);
}