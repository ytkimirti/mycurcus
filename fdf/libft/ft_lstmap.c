/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:13:46 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/06 15:39:03 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_curr;
	t_list	*dummy;

	if (!f)
		return (NULL);
	dummy = ft_lstnew(NULL);
	if (!dummy)
		return (NULL);
	new_curr = dummy;
	while (lst != NULL)
	{
		new_curr->next = ft_lstnew((*f)(lst->content));
		if (new_curr->next == NULL)
		{
			ft_lstclear(&(dummy->next), del);
			free(dummy);
			return (NULL);
		}
		lst = lst->next;
		new_curr = new_curr->next;
	}
	new_curr = dummy->next;
	free(dummy);
	return (new_curr);
}
