/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:39:26 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:39:55 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_itoalen(int n)
{
	long int		multi;
	size_t			i;
	long int		temp;

	multi = 10;
	i = 0;
	temp = n;
	if (n < 0)
	{
		temp = -temp;
		i++;
	}
	while (temp / multi > 0)
	{
		multi *= 10;
		i++;
	}
	return (i + 1);
}

char			*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	int			unit;
	long int	temp;

	len = ft_itoalen(n);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = 0;
	if (n == 0)
		str[0] = '0';
	temp = n;
	if (n < 0)
	{
		str[0] = '-';
		temp = -temp;
	}
	while (temp > 0)
	{
		unit = temp % 10;
		temp = temp / 10;
		str[len - 1] = unit + '0';
		len--;
	}
	return (str);
}
/*
**int		main(void)
**{
**	char	*t;
**
**	printf("%s", t = ft_itoa(-2147483648LL));
**	free(t);
**	return (0);
**}
*/
