/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:30:54 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:43:33 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	size;

	i = 0;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (size < len)
		len = size;
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len && i <= len - 1 && (start + i) < size)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
/*
**int	main(void)
**{
**	char const		*s = "lorem ipsum dolor sit amet";
**	char			*t;
**
**	printf("%s", t = ft_substr(s, 400, 20));
**	free(t);
**}
*/
