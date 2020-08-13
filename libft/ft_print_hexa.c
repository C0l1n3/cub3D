/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:52:16 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:41:36 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_process_unsigned(va_list *args, t_param *datas)
{
	int	tab[4];

	tab[0] = va_arg(*args, unsigned int);
	tab[1] = ft_hexa_len(tab[0], datas);
	tab[2] = datas->p_nb;
	tab[3] = datas->s_nb;
	if (datas->is_p && datas->is_symbol == '0' && datas->p_nb >= 0)
		datas->is_symbol = ' ';
	if (tab[1] > datas->p_nb && tab[0])
		datas->p_nb = tab[1];
	if (!tab[0] && !datas->is_p)
		tab[3] = tab[3] - tab[1];
	ft_print_unsigned(datas, tab);
	return (datas->nb_printed);
}

void	ft_print_unsigned(t_param *datas, int *tab)
{
	while (!datas->is_minus && tab[3] > datas->p_nb && tab[3] > 0)
	{
		ft_putchar_printf(datas->is_symbol, datas);
		tab[3]--;
	}
	while (datas->is_p && tab[2] > tab[1])
	{
		ft_putchar_printf('0', datas);
		tab[2]--;
	}
	datas->s_nb = tab[3];
	ft_putnbr_unsigned(tab[0], datas);
	if (!tab[0] && datas->is_p && !datas->p_nb)
		tab[3]--;
	while (datas->is_minus && tab[3] > datas->p_nb && tab[3] > 0)
	{
		ft_putchar_printf(datas->is_symbol, datas);
		tab[3]--;
	}
}

int		ft_hexa_len(long long int nbr, t_param *datas)
{
	int	len;
	int	base;

	len = 0;
	base = (datas->data_type == 'u') ? 10 : 16;
	if (nbr < 0)
		nbr = 4294967295 + nbr + 1;
	if (nbr == 0 && !datas->is_p)
		return (1);
	while (nbr / base != 0)
	{
		len++;
		nbr = nbr / base;
	}
	len++;
	return (len);
}

int		ft_process_hexa(va_list *args, t_param *datas)
{
	int	tab[4];

	tab[0] = va_arg(*args, unsigned int);
	tab[1] = ft_hexa_len(tab[0], datas);
	if (datas->data_type == 'p' || (datas->is_hash && tab[0] > 0))
		datas->s_nb -= 2;
	tab[2] = datas->p_nb;
	tab[3] = datas->s_nb;
	if (datas->is_p && datas->is_symbol == '0' && datas->p_nb >= 0)
		datas->is_symbol = ' ';
	if (tab[1] > datas->p_nb && tab[0])
		datas->p_nb = tab[1];
	if (!tab[0] && !datas->is_p)
		tab[3] = tab[3] - tab[1];
	if (datas->is_hash && datas->is_symbol != ' ' && tab[0] > 0)
		ft_putchar_ptr(datas, tab[0], tab[1]);
	while (!datas->is_minus && tab[3] > datas->p_nb && tab[3] > 0)
	{
		ft_putchar_printf(datas->is_symbol, datas);
		tab[3]--;
	}
	ft_print_hexa(datas, tab);
	return (datas->nb_printed);
}

void	ft_print_hexa(t_param *datas, int *tab)
{
	if (datas->is_hash && datas->is_symbol != '0' && tab[0] > 0)
		ft_putchar_ptr(datas, tab[0], tab[1]);
	while (datas->is_p && tab[2] > tab[1])
	{
		ft_putchar_printf('0', datas);
		tab[2]--;
	}
	datas->s_nb = tab[3];
	if (datas->data_type == 'p')
		ft_putchar_ptr(datas, tab[0], tab[1]);
	if (datas->data_type == 'x' || datas->data_type == 'p')
		ft_putnbr_base(tab[0], "0123456789abcdef", datas);
	else
		ft_putnbr_base(tab[0], "0123456789ABCDEF", datas);
	if (!tab[0] && datas->is_p && !datas->p_nb)
		tab[3]--;
	while (datas->is_minus && tab[3] > datas->p_nb && tab[3] > 0)
	{
		ft_putchar_printf(datas->is_symbol, datas);
		tab[3]--;
	}
}
