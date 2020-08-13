/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:20:08 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:42:26 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd >= 0)
	{
		if (n >= 0)
		{
			if (n >= 10)
				ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(n % 10 + '0', fd);
		}
		else
		{
			ft_putchar_fd('-', fd);
			if (n <= -10)
				ft_putnbr_fd(n / -10, fd);
			ft_putchar_fd(n % -10 * -1 + '0', fd);
		}
	}
}
/*
**int	main(void)
**{
**	ft_putnbr_fd(-2147483648, 2);
**}
*/
