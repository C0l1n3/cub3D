/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_str_to_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:50:07 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/13 15:58:25 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_chain	*lstcharnew(char *content)
{
	t_chain	*tmp;

	if (!(tmp = malloc(sizeof(t_chain))))
		return (NULL);
	if (!content)
		tmp->content = NULL;
	else
		tmp->content = ft_strdup(content);
	tmp->next = NULL;
	return (tmp);
}

void	free_lstchar(t_chain *lst)
{
	t_chain		*ptr;

	while (lst != NULL)
	{
		ptr = lst;
		lst = lst->next;
		free_safe((void**)&(ptr->content));
		free_safe((void**)&(ptr));
	}
}

t_chain	*lstcharlast(t_chain *lst)
{
	t_chain *tmp;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	lstcharadd_back(t_chain **alst, t_chain *new)
{
	if (*alst == NULL)
		*alst = new;
	else
		lstcharlast(*alst)->next = new;
}
