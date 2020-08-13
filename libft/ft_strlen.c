/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:08:52 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:43:08 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t size;

	size = 0;
	while (s && s[size])
		size++;
	return (size);
}
/*
**int	main(void)
**{
**const char	*str = "J'aime les pates";
**printf("%zu\n", ft_strlen(str));
**printf("%zu", strlen(str));
**}
*/
