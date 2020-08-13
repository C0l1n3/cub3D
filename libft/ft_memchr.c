/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:06:21 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:40:53 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	tempchar;
	char	*tempstr;

	i = 0;
	tempchar = (char)c;
	tempstr = (char*)s;
	while (i < n && s)
	{
		if (tempstr[i] == tempchar)
			return ((void*)&tempstr[i]);
		i++;
	}
	return (NULL);
}
/*
**int	main(void)
**{
**const char *str;
**const char *str2;
**
**char *pouet = "z";
**char *lolzer = (char *)&pouet[2];
**lolzer = "aaaaaaaaaa";
**str = ft_memchr(pouet, 'a', 50);
**str2 = memchr(pouet, 'a', 50);
**printf("%s\n%s", str, str2);
**}
*/
