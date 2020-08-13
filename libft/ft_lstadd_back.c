/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:09:27 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:40:02 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*ptr;

	if (!*alst)
		*alst = new;
	ptr = ft_lstlast(*alst);
	if (ptr && new)
	{
		ptr->next = new;
		new->next = NULL;
	}
}
