/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:03:30 by vst-pier          #+#    #+#             */
/*   Updated: 2023/01/23 14:52:29 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new_string;
	unsigned long	i;

	i = 0;
	if (!s)
		return (NULL);
	new_string = malloc(sizeof(char) * (len + 1));
	if (new_string == NULL)
		return (NULL);
	while (i < len && s[start + i] && start < ft_strlen(s))
	{
		new_string[i] = s[start + i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
