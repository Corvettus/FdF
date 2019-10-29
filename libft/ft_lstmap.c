/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 04:33:47 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/20 04:33:49 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*lst2;

	if (!f || !lst)
		return (NULL);
	if (!(lst2 = f(lst)))
		return (NULL);
	newlst = lst2;
	while (lst->next)
	{
		lst = lst->next;
		if (!(lst2->next = f(lst)))
		{
			while (newlst)
			{
				lst2 = newlst->next;
				free(newlst);
				newlst = lst2;
			}
			return (NULL);
		}
		lst2 = lst2->next;
	}
	return (newlst);
}
