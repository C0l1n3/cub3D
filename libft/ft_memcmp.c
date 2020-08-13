/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:08:12 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:40:58 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*s1b;
	const char	*s2b;
	size_t		i;

	s1b = (const char*)s1;
	s2b = (const char*)s2;
	i = 0;
	if (n == 0 || !s1 || !s2)
		return (0);
	while (i < n - 1 && s1b[i] == s2b[i])
		i++;
	return ((unsigned char)s1b[i] - (unsigned char)s2b[i]);
}
/*
**int	main(void)
**{
**printf("%d : %d\n", memcmp("\200", "\0", 4), ft_memcmp("\200", "\0", 4));
**return (0);
**}
*/
