/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:58:45 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:43:48 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_endl(char *str)
{
	int	len;

	len = 0;
	while (str && str[len])
	{
		if (str[len] == '\n')
			return (len);
		len++;
	}
	return (-1);
}

char	*ft_cut(char **str, int len)
{
	char	*before_n;
	char	*temp;

	temp = *str;
	before_n = NULL;
	if (str && *str)
		if (!(before_n = ft_substr(*str, 0, len)))
			return (NULL);
	if (!(*str = ft_substr(*str, len + 1, (ft_strlen(*str) - len - 1))))
		return (NULL);
	ft_free_safe(&temp);
	return (before_n);
}
