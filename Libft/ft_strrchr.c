/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:45:51 by tgeler            #+#    #+#             */
/*   Updated: 2025/06/03 19:45:51 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_strrchr(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;

	index = ft_strlen_strrchr(s);
	while (1)
	{
		if (s[index] == (char)c)
			return ((char *)(s + index));
		if (index == 0)
			break ;
		index--;
	}
	return (NULL);
}
