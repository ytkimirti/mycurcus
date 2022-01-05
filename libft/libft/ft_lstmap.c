/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:13:46 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/05 20:27:05 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*src_curr;
	t_list	*new_curr;
	t_list	*dummy;

	if (!f)
		return (NULL);

	dummy = ft_lstnew(NULL);
	if (!dummy)
		return (NULL);

	src_curr = lst;
	new_curr = dummy;
	while (src_curr != NULL)
	{
		new_curr->next = ft_lstnew((*f)(src_curr->content));
		if (new_curr->next == NULL)
		{
			ft_lstclear(&(dummy->next), del);
			free(dummy->content);
			free(dummy);
			return (NULL);
		}
		src_curr = src_curr->next;
		new_curr = new_curr->next;
	}
	return (dummy->next);
}


/*t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))*/
/*{*/
	/*t_list	*src_curr;*/
	/*t_list	*new_curr;*/
	/*t_list	*dummy;*/

	/*if (!f)*/
		/*return (NULL);*/
	/*dummy = ft_lstnew(NULL);*/
	/*if (!dummy)*/
		/*return (NULL);*/
	/*src_curr = lst;*/
	/*new_curr = dummy;*/
	/*while (src_curr != NULL)*/
	/*{*/
		/*new_curr->next = ft_lstnew((*f)(src_curr->content));*/
		/*if (new_curr->next == NULL)*/
		/*{*/
			/*ft_lstclear(&(dummy->next), del);*/
			/*free(dummy->content);*/
			/*free(dummy);*/
			/*return (NULL);*/
		/*}*/
		/*src_curr = src_curr->next;*/
		/*new_curr = new_curr->next;*/
	/*}*/
	/*return (dummy->next);*/
/*}*/
