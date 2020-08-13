/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:26:24 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:43:29 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	size_t			size;

	i = 0;
	size = ft_strlen(s1) - 1;
	if (!s1)
		return (NULL);
	if (!*s1)
		return (ft_strdup(s1));
	if (!set)
		return (ft_substr(s1, i, size + 1));
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[size]) && size > i)
		size--;
	return (ft_substr(s1, i, (size - (size_t)i + 1)));
}
/*
**int		main(void)
**{
**	char	*t;
**
**	printf("%s", t = ft_strtrim("  jdyjsr srh sth  ", " "));
**	free(t);
**	return (0);
**}
*/
