/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:52:23 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:42:12 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_nb(const char *str, va_list *args, int *index, t_param *datas)
{
	int nb;

	nb = 0;
	while (ft_isdigit(str[*index]))
	{
		nb = (10 * nb) + str[*index] - '0';
		*index += 1;
		if (nb < 0)
		{
			datas->is_minus = 1;
			nb = -nb;
		}
	}
	if (str[*index] == '*')
	{
		nb = va_arg(*args, int);
		*index += 1;
	}
	return (nb);
}

void	ft_process_flags2(const char *str, int index, va_list *args,
t_param *datas)
{
	if (str[index] == '*' || ft_isdigit(str[index]))
	{
		datas->s_nb = ft_get_nb(str, args, &index, datas);
		if (datas->s_nb < 0)
		{
			datas->is_minus = 1;
			datas->s_nb = -datas->s_nb;
		}
	}
	if (str[index] == '.')
	{
		datas->is_p = 1;
		index++;
		if (str[index] == '*' || ft_isdigit(str[index]))
			datas->p_nb = ft_get_nb(str, args, &index, datas);
	}
	if (datas->is_minus && datas->is_symbol == '0')
		datas->is_symbol = ' ';
	datas->data_type = str[index];
}

void	ft_process_flags1(const char *str, int index,
va_list *args, t_param *datas)
{
	while (str[index] == '#' || str[index] == '-' || str[index] == '0'
	|| str[index] == '+' || str[index] == ' ')
	{
		if (str[index] == '#')
			datas->is_hash = 1;
		if (str[index] == '-')
			datas->is_minus = 1;
		if (str[index] == '0')
			datas->is_symbol = '0';
		if (str[index] == '+')
			datas->is_plus = '+';
		if (str[index] == ' ' && !datas->is_plus)
			datas->is_plus = ' ';
		index++;
	}
	ft_process_flags2(str, index, args, datas);
}

int		ft_process_data(const char *str, int index,
			va_list *args, t_param *datas)
{
	ft_process_flags1(str, index++, args, datas);
	while (ft_is_flag(str[index]))
		index++;
	if (datas->data_type == 'c' || datas->data_type == '%')
		return (ft_print_char(args, datas));
	if (datas->data_type == 's')
		return (ft_process_str(args, datas));
	if (datas->data_type == 'd' || datas->data_type == 'i')
		return (ft_process_integer(args, datas));
	if (datas->data_type == 'p')
		return (ft_process_ptr(args, datas));
	if (datas->data_type == 'x' || datas->data_type == 'X')
		return (ft_process_hexa(args, datas));
	if (datas->data_type == 'u')
		return (ft_process_unsigned(args, datas));
	if (datas->data_type == 'n')
		return (ft_process_n(args, datas));
	return (-1);
}

int		ft_process_n(va_list *args, t_param *datas)
{
	int		*nb;

	nb = va_arg(*args, void *);
	if (nb)
	{
		*nb = datas->nb_printed;
		return (*nb);
	}
	return (datas->nb_printed);
}
