/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:54:50 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:43:04 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!dst || !src)
		return (0);
	if (size == 0 && src)
		return (ft_strlen(src));
	while (src[j] && src)
		j++;
	while (i <= size - 2 && src[i] && src && dst)
	{
		dst[i] = src[i];
		i++;
	}
	if (dst)
		dst[i] = '\0';
	return (j);
}
/*
**int	main(void)
**{
**	char		*s1 = "rrrrrr";
**	const char	*s2 = "lorem ipsum dolor sit amet";
**	s2 = NULL;
**	char		*s3 = "rrrrrr";
**	const char	*s4 = "lorem ipsum dolor sit amet";
**	s4 = NULL;
**
**	printf("%zu\n", ft_strlcpy(s1, s2, 0));
**	printf("%zu\n", strlcpy(s3, s4, 0));
**	printf("%s\n%s", s1, s3);
**}
*/
