/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:11:23 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:39:22 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (((47 < c && c < 58) || (64 < c && c < 91))
			|| (96 < c && c < 123))
		return (1);
	return (0);
}
/*
**int	main(void)
**{
**int	c = ':';
**
**if (ft_isalnum(c) == 1)
**printf("%d is an alphabetical or numerical character", c);
**else
**printf("%d is not an alphabetical nor a numerical character", c);
**return (0);
**}
*/
