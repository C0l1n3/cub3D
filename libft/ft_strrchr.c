/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:40:38 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:43:25 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s[i])
		return ((char*)&s[i]);
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char*)&s[i]);
		i--;
	}
	return (NULL);
}
/*
**int	main(void)
**{
**	char	str[] = "";
**
**	printf("%s\n", ft_strrchr(str, '\0'));
**	printf("%s", strrchr(str, '\0'));
**	return (0);
**}
*/
