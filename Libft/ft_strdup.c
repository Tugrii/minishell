/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:44:12 by tgeler            #+#    #+#             */
/*   Updated: 2025/06/03 19:44:12 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_dup(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dynamic_memory;
	size_t	i;

	i = 0;
	dynamic_memory = (char *)malloc(ft_strlen_dup(s) + 1);
	if (!dynamic_memory)
		return (NULL);
	while (s[i] != '\0')
	{
		dynamic_memory[i] = s[i];
		i++;
	}
	dynamic_memory[i] = '\0';
	return (dynamic_memory);
}
