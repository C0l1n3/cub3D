/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:47:56 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:41:44 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_process_integer(va_list *args, t_param *datas)
{
	long	nb_long;
	int		tab[4];

	tab[0] = va_arg(*args, int);
	tab[1] = ft_intlen(tab[0]);
	tab[2] = datas->s_nb;
	tab[3] = datas->p_nb;
	nb_long = 0;
	if (tab[0] < 0)
		nb_long = -tab[0];
	else if (tab[0] >= 0)
		nb_long = tab[0];
	if (datas->is_symbol == '0' && datas->is_p && (tab[3] <= tab[1]
	|| tab[2]))
		datas->is_symbol = ' ';
	if (datas->p_nb)
		datas->p_nb = datas->p_nb - tab[1];
	if (datas->p_nb < 0)
	{
		datas->p_nb = 0;
		datas->is_p = 0;
	}
	return (ft_print_int(datas, tab, nb_long));
}

int		ft_print_int(t_param *datas, int *tab, long nb_long)
{
	if (tab[0] < 0)
		tab[1]++;
	if (datas->s_nb)
		datas->s_nb = datas->s_nb - (datas->p_nb + tab[1]);
	if (datas->is_symbol == '0' && tab[0] < 0)
		ft_putchar_printf('-', datas);
	while (!datas->is_minus && datas->s_nb > 0)
	{
		ft_putchar_printf(datas->is_symbol, datas);
		datas->s_nb--;
	}
	if (tab[0] < 0 && datas->is_symbol != '0')
		ft_putchar_printf('-', datas);
	while (datas->is_p && datas->p_nb > 0)
	{
		ft_putchar_printf('0', datas);
		datas->p_nb--;
	}
	return (ft_print_int2(datas, tab, nb_long));
}

int		ft_print_int2(t_param *datas, int *tab, long nb_long)
{
	if (tab[0])
		ft_putnbr_base(nb_long, "0123456789", datas);
	else if (!tab[0] && (tab[3] || !datas->is_p))
		ft_putchar_printf('0', datas);
	else if (!tab[0] && !tab[3] && tab[2])
		ft_putchar_printf(' ', datas);
	while (datas->is_minus && datas->s_nb > 0)
	{
		ft_putchar_printf(' ', datas);
		datas->s_nb--;
	}
	return (datas->nb_printed);
}
