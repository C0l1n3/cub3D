/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:03:38 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:41:09 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && dst && src)
	{
		((char*)dst)[i] = ((const char*)src)[i];
		i++;
	}
	return (dst);
}
/*
**intmain(void)
**{
**charstr1[100] = "Geeksfor";
**charstr1b[100] = "aaa";
**charstr2[100] = "Geeksfor";
**charstr2b[100] = "aaa";
**
**printf("%s\n", memcpy(str1b, str1, 15));
**printf("%s", ft_memcpy(str2b, str2, 15));
**return (0);
**}
*/
