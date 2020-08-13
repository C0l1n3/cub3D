/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:58:36 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:39:06 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!(ptr = malloc(count * size)))
		return (NULL);
	while (i < (count * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void*)ptr);
}
/*
**int	main(void)
**{
**void	*a;
**void	*b;
**
**printf("%s", (a = calloc (5, 10)));
**printf("%s", (b = ft_calloc(5, 10)));
**free(a);
**free(b);
**
**}
*/
