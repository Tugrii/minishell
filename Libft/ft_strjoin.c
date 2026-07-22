/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:44:19 by tgeler            #+#    #+#             */
/*   Updated: 2025/06/03 19:44:19 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_join(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	prefix_length;
	size_t	j;

	j = 0;
	prefix_length = ft_strlen_join(s1);
	i = 0;
	new_str = (char *)malloc(ft_strlen_join(s2) + prefix_length + 1);
	if (!new_str)
		return (NULL);
	while (i < prefix_length)
	{
		new_str[i] = s1[i];
		i++;
	}
	while (i < (ft_strlen_join(s2) + prefix_length))
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}
