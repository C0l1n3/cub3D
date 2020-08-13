/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:51:47 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:43:13 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s || (!(str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1)))))
		return (NULL);
	while (s[i])
	{
		if (!(str[i] = f(i, s[i])))
			return (NULL);
		i++;
	}
	str[i] = 0;
	return (str);
}
