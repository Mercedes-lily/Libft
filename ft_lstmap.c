/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:35:27 by vst-pier          #+#    #+#             */
/*   Updated: 2023/01/23 09:42:06 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list * temp;
	int len;
	
	if(!lst || !f || !del)
		return(lst);
	ft_lstiter(lst, *f);
	len = ft_lstsize(lst);
	new = malloc(sizeof(t_list) * (len + 1));
	temp = new;
	while(lst)
	{
		temp = ft_lstnew(lst->content);
		if(!temp)
			del(temp);
		lst = lst->next;
	}
	temp->next = NULL;
	return(new);
}

