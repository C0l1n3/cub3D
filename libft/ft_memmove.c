/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:05:13 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:41:16 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overlap(void *dst, const void *src)
{
	if (!dst || !src)
		return (-1);
	if (dst <= src)
		return (0);
	if (dst >= src)
		return (1);
	return (-1);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	int		check;

	i = 0;
	check = ft_overlap(dst, src);
	while (len > 0 && check > 0)
	{
		((char*)dst)[len - 1] = ((char*)src)[len - 1];
		len--;
	}
	while (i < len && !check)
	{
		((char*)dst)[i] = ((const char*)src)[i];
		i++;
	}
	return (dst);
}
/*
**int	main(void)
**{
**char	str1[] = "I am very good .....";
**char	str1b[] = "blop";
**char	str2[] = "I am very good .....";
**char	str2b[] = "blop";
**printf("%s\n", ft_memmove(str1 + 15, str1b, 6));
**printf("%s", memmove(str2 + 15, str2b, 6));
**return (0);
**}
*/
