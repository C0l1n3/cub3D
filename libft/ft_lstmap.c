/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:38:58 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:40:38 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*newlst;

	if (!lst || !f || !del)
		return (NULL);
	if (!(newlst = ft_lstnew(f(lst->content))))
	{
		ft_lstdelone(newlst, del);
		return (NULL);
	}
	temp = newlst;
	while (lst->next)
	{
		lst = lst->next;
		ft_lstadd_back(&newlst, ft_lstnew(f(lst->content)));
		if (!(newlst))
		{
			ft_lstclear(&temp, del);
			return (NULL);
		}
		newlst = newlst->next;
	}
	return (temp);
}
/*
**void	ft_del(void *content)
**{
**	*(int*)content = 0;
**	return ;
**}
**
**void	*ft_m(void *content)
**{
**	void	*newcontent;
**
**	newcontent = malloc(sizeof(int));
**	*((int*)newcontent) = *((int*)content) + 10;
**	return (newcontent);
**}
**
**int	main(void)
**{
**	int	*tab[] = {1};
**	int	*tab2 = {5};
**	int	*tab3 = {9};
**	t_list	*lst;
**
**	lst = ft_lstnew(tab);
**	ft_lstadd_back(&lst, tab2);
**	ft_lstadd_back(&lst, tab3);
**	ft_lstmap(lst, ft_m, del)
**
**}
*/
