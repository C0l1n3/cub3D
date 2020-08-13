/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:55:28 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 11:58:24 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_ptr(t_param *datas, long int nbr, int hexa_len)
{
	int	i;

	(void)hexa_len;
	i = 0;
	ft_putchar_printf('0', datas);
	if (datas->data_type == 'X')
		ft_putchar_printf('X', datas);
	else
		ft_putchar_printf('x', datas);
	if (nbr < 0)
	{
		while (i < 8)
		{
			ft_putchar_printf('f', datas);
			i++;
		}
	}
}

int		ft_ptr_len(long long int nbr, t_param *datas)
{
	int	len;

	len = 0;
	if (nbr == 0 && !datas->is_p)
		return (1);
	if (nbr < 0)
	{
		nbr = 4294967296 + nbr;
		len = 8;
	}
	while (nbr >= 16)
	{
		len++;
		nbr = nbr / 16;
	}
	if (nbr)
		len++;
	return (len);
}

int		ft_process_ptr(va_list *args, t_param *datas)
{
	long long int	nbr;
	int				hexa_len;
	int				tab[2];

	nbr = va_arg(*args, long long int);
	hexa_len = ft_ptr_len(nbr, datas);
	if (datas->data_type == 'p' || (datas->is_hash && nbr > 0))
		datas->s_nb -= 2;
	if (datas->s_nb > datas->p_nb && datas->is_symbol == '0' && datas->is_p)
		datas->is_symbol = ' ';
	datas->p_nb = (datas->p_nb - hexa_len < 0) ? 0 : datas->p_nb - hexa_len;
	datas->s_nb = (datas->s_nb - datas->p_nb - hexa_len < 0) ? 0 : datas->s_nb -
	datas->p_nb - hexa_len;
	tab[0] = datas->p_nb;
	tab[1] = datas->s_nb;
	ft_print_ptr(datas, nbr, tab);
	return (datas->nb_printed);
}

void	ft_print_ptr(t_param *datas, long int nbr, int *tab)
{
	if (datas->is_hash && datas->is_symbol != ' ' && nbr > 0)
		ft_putchar_ptr(datas, nbr, 0);
	while (!datas->is_minus && tab[1] > 0)
	{
		ft_putchar_printf(datas->is_symbol, datas);
		tab[1]--;
	}
	if (datas->is_hash && datas->is_symbol != '0' && nbr > 0)
		ft_putchar_ptr(datas, nbr, 0);
	while (datas->is_p && tab[0] > 0)
	{
		ft_putchar_printf('0', datas);
		tab[0]--;
	}
	if (datas->data_type == 'p')
		ft_putchar_ptr(datas, nbr, 0);
	if (datas->data_type == 'x' || datas->data_type == 'p')
		ft_putnbr_base(nbr, "0123456789abcdef", datas);
	else
		ft_putnbr_base(nbr, "0123456789ABCDEF", datas);
	while (datas->is_minus && tab[1] > 0)
	{
		ft_putchar_printf(datas->is_symbol, datas);
		tab[1]--;
	}
}
