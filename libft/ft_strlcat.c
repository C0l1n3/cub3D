/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:30:56 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:42:59 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size && dst[i] && dst)
		i++;
	j = 0;
	while ((j + i) < (size - 1) && size && src[j] && src && dst)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size && dst)
		dst[i + j] = '\0';
	while (src[j] && src)
		j++;
	return (i + j);
}
/*
**int	main(void)
**{
**	char    *dest;
**
**	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
**		return (0);
**	memset(dest, 0, 15);
**	memset(dest, 'r', 6);
**	dest[10] = 'a';
**	printf("%s\n%zu", dest, ft_strlcat(dest, "lorem ipsum dolor sit amet", 1));
**	free(dest);
**}
*/
