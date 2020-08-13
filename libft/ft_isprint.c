/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:18:22 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:39:50 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (31 < c && c < 127)
		return (1);
	return (0);
}
/*
**intmain(void)
**{
**intc = '\0';
**
**if (ft_isprint(c) == 1)
**printf("%d is a printable character", c);
**else
**printf("%d is not a printable character", c);
**return (0);
**}
*/
