/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:44:37 by vst-pier          #+#    #+#             */
/*   Updated: 2023/01/23 14:04:22 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_clean(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

int	nb_mots(char const *s, char c)
{
	int	nb;
	int	i;

	if(!s)
		return(0);
	i = 0;
	nb = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			nb++;
		i++;
	}
	return (nb);
}

char	**ft_split(char const *s, char c)
{
	char **tab_split;
	int letters;
	int i ;
	int index_tab;
	int start;
	char set[1];

	start = 0;
	i = -1;
	index_tab = 0;
	letters = 0;
	set[0] = c;
	s = ft_strtrim(s, set);
	tab_split = ft_calloc((nb_mots(s, c)+ 1), sizeof(char*));
	if(tab_split == NULL)
		return(NULL);
	while(s[i++])
	{
		if(s[i] != c)
			letters++;
		else if(s[i] == c && s[i + 1] != c)
		{
			tab_split[index_tab] = ft_substr(s, start , letters + 1);
			if (!tab_split[index_tab])
				return(ft_clean);
			index_tab++;
			letters = 0;
			start = i + 1;
		}
		i++;
	}
	return(tab_split);
}
