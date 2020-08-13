/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:14:48 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:40:29 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int	size;
	int	i;

	size = ft_lstsize(lst);
	i = 0;
	while (i < size)
	{
		f(lst->content);
		lst = lst->next;
		i++;
	}
}
