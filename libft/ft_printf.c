/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:43:40 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:42:04 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_param	ft_initialize(t_param *datas)
{
	datas->data_type = '\0';
	datas->is_minus = 0;
	datas->is_plus = '\0';
	datas->s_nb = 0;
	datas->is_symbol = ' ';
	datas->is_p = 0;
	datas->p_nb = 0;
	datas->is_hash = 0;
	return (*datas);
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	t_param datas;
	int		i;

	i = -1;
	datas.nb_printed = 0;
	va_start(args, str);
	while (str && str[++i])
	{
		datas = ft_initialize(&datas);
		while (str[i] != '%' && str[i])
		{
			ft_putchar_printf(str[i], &datas);
			i++;
		}
		if (!str[i])
			break ;
		i++;
		if (ft_process_data(str, i, &args, &datas) < 0)
			return (-1);
		while (!(ft_is_data_type(str[i])))
			i++;
	}
	va_end(args);
	return (datas.nb_printed);
}
