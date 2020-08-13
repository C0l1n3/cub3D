/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:18:22 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:40:42 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newlink;

	if (!(newlink = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
		newlink->content = NULL;
	else
		newlink->content = content;
	newlink->next = NULL;
	return (newlink);
}
