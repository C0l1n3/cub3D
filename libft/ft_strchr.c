/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:57:23 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:42:46 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (c == 0)
		return ((char*)&s[ft_strlen(s)]);
	while (s[i] && s)
	{
		if (s[i] == (char)c)
			return ((char*)&s[i]);
		i++;
	}
	return (NULL);
}
/*
**int		main(void)
**{
**	const char	*s;
**	int			c;
**
**	s = "";
**	c = '\0';
**	printf("%s\n", ft_strchr(s, c));
**	printf("%s", strchr(s, c));
**}
*/
