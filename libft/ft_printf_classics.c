/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_classics.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:56:01 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 11:59:51 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putchar_printf(char c, t_param *datas)
{
	write(1, &c, 1);
	return (datas->nb_printed++);
}

int		ft_putnbr_unsigned(unsigned int nb, t_param *datas)
{
	if (nb == 0 && datas->is_p && datas->p_nb == 0)
	{
		if (datas->s_nb)
			ft_putchar_printf(' ', datas);
		return (0);
	}
	if (nb >= 10)
	{
		ft_putnbr_unsigned(nb / 10, datas);
		ft_putchar_printf(nb % 10 + '0', datas);
	}
	else
		ft_putchar_printf(nb + '0', datas);
	return (0);
}

size_t	ft_intlen(int n)
{
	long int	multi;
	size_t		i;
	long int	temp;

	multi = 10;
	i = 0;
	temp = n;
	if (n < 0)
	{
		temp = -temp;
	}
	while (temp / multi > 0)
	{
		multi *= 10;
		i++;
	}
	return (i + 1);
}

int		ft_putnbr_base(long long int nbr, char *base, t_param *datas)
{
	long long	int x;
	long long	int y;

	y = ft_strlen(base);
	x = nbr;
	if (x < 0)
		x = 4294967296 + x;
	if (nbr == 0 && datas->is_p && datas->p_nb == 0)
	{
		if (datas->s_nb && datas->data_type != 'p')
			ft_putchar_printf(' ', datas);
		return (0);
	}
	if (x >= y)
	{
		ft_putnbr_base(x / y, base, datas);
		ft_putchar_printf(base[x % y], datas);
	}
	else if (datas->s_nb && datas->is_p && !datas->p_nb && !x)
		ft_putchar_printf(' ', datas);
	else
		ft_putchar_printf(base[x], datas);
	return (0);
}
