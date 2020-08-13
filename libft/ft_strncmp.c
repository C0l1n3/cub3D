/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:56:37 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 17:21:41 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0 || !s1 || !s2)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	if (ft_isascii(s1[i]) && ft_isascii(s2[i]))
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (1);
}
/*
**int main(void)
**{
**	printf("%d", ft_strncmp("\200", "a", 4));
**	printf("\n%d", strncmp("\200", "a", 4));
**	return (0);
**}
*/
