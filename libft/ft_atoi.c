/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:20:45 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:38:48 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	long long	nb;
	int			sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (!str)
		return (0);
	while ((str[i] == ' ' || str[i] == '\f' || str[i] == '\t')
			|| (str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
		if ((nb = nb * 10 + (str[i++] - '0')) < 0)
			return (-1);
	return (sign * nb);
}
/*
**int	main()
**{
**printf("%d\n", ft_atoi("-2147483648"));
**printf("%d", atoi("-2147483648"));
**}
*/
