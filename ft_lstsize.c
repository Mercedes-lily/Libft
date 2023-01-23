/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:22:21 by vst-pier          #+#    #+#             */
/*   Updated: 2023/01/19 14:00:20 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int nb; 

	nb = 1;
	if(lst == NULL)
		return(NULL);
	while(lst->next != NULL)
	{
		nb++;
		lst = lst->next;
	}
	if(lst->next == NULL)
	return(nb);
}