/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:00:04 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:41:20 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char*)b;
	while (i < len && temp)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (temp);
}
/*
**int	main(void)
**{
**char	*str = "Salut mon pote";
**char	*str2 = "Salut mon pote";
**
**void	*s = &str;
**void	*s2 = &str2;
**printf("%s\n", ft_memset(s, '*', 4));
**printf("%s", memset(s2, '*', 4));
**free(str);
**free(str2);
**}
*/
