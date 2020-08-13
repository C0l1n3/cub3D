/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:50:07 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:40:14 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	int		size;
	int		i;
	t_list	*ptr;

	ptr = *lst;
	size = ft_lstsize(*lst);
	i = 0;
	while (i < size)
	{
		ft_lstdelone(ptr, del);
		ptr = ptr->next;
		i++;
	}
	*lst = NULL;
}
