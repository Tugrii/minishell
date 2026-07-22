/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:46:00 by tgeler            #+#    #+#             */
/*   Updated: 2025/06/03 19:46:00 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dynamic;
	size_t			i;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	i = 0;
	dynamic = malloc(sizeof(char) * (len + 1));
	if (!dynamic)
		return (NULL);
	dynamic[len] = '\0';
	s += start;
	while (i < len)
	{
		dynamic[i] = *(s + i);
		i++;
	}
	return (dynamic);
}
