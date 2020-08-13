/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:12:46 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:43:21 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[i] == '\0')
		return ((char*)s1);
	while (s1[i] && i <= len)
	{
		j = 0;
		while ((s2[j] == s1[i + j] || s2[j] == '\0')
				&& (i + j <= len))
		{
			if (s2[j] && s2[j] == s1[i + j])
				j++;
			else if (s2[j] == '\0')
				return ((char*)&s1[i]);
		}
		if (s1[i] == '\0')
			break ;
		i++;
	}
	return (0);
}
/*
**int	main(void)
**{
**printf("Test de ft_strnstr :\n");
**printf("ft_strnstr(\"bonjour\", \"njo\", 5) : njour : ");
**printf("%s\n", ft_strnstr("bonjour", "njo", 5));
**}
*/
