/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:31:52 by xacoquan          #+#    #+#             */
/*   Updated: 2014/11/06 02:17:47 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void ft_memdel(void **ap)
{
	free(*ap);
	*ap = NULL;
}
