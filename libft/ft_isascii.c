/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:12:00 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:39:35 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}
/*
**int	main(void)
**{
**int	c = 165;
**
**if (ft_isascii(c) == 1)
**printf("%d is an ascii number", c);
**else
**printf("%d is not an ascii number", c);
**}
*/
