/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:09:51 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:39:28 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int a)
{
	if (97 <= a && a <= 122)
		return (1);
	else if (65 <= a && a <= 90)
		return (1);
	return (0);
}
/*
**int	main(void)
**{
**int	a;
**
**a = 'p';
**printf("%d\n%d", isalpha(a), ft_isalpha(a));
**return (0);
**}
*/
