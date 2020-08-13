/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:04:06 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:41:29 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_char(va_list *args, t_param *datas)
{
	char	letter;

	if (datas->data_type == 'c')
		letter = (char)va_arg(*args, int);
	else
		letter = '%';
	while (!datas->is_minus && datas->s_nb > 1)
	{
		ft_putchar_printf(datas->is_symbol, datas);
		datas->s_nb--;
	}
	ft_putchar_printf(letter, datas);
	while (datas->is_minus && datas->s_nb > 1)
	{
		ft_putchar_printf(datas->is_symbol, datas);
		datas->s_nb--;
	}
	return (datas->nb_printed);
}

int		ft_process_str(va_list *args, t_param *datas)
{
	int		len;
	char	*s;

	s = (char*)va_arg(*args, char *);
	if (!s)
		s = "(null)";
	if (datas->is_p && !datas->p_nb)
		s = "";
	len = ft_strlen(s);
	if (!datas->is_p || datas->p_nb < 0)
		datas->p_nb = len;
	if (datas->p_nb < 0)
	{
		datas->is_minus = 1;
		datas->p_nb = -datas->p_nb;
	}
	if (datas->p_nb < len)
		datas->s_nb = datas->s_nb + (len - datas->p_nb);
	datas->s_nb = (len < datas->s_nb) ? datas->s_nb - len : 0;
	return (ft_print_str(datas, s));
}

int		ft_print_str(t_param *datas, char *s)
{
	int i;

	i = 0;
	while (!datas->is_minus && datas->s_nb > 0)
	{
		ft_putchar_printf(' ', datas);
		datas->s_nb--;
	}
	while (s[i] && i < datas->p_nb)
	{
		ft_putchar_printf(s[i], datas);
		i++;
	}
	while (datas->is_minus && datas->s_nb > 0)
	{
		ft_putchar_printf(' ', datas);
		datas->s_nb--;
	}
	return (datas->nb_printed);
}
