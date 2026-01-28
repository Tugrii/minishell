/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:44:45 by tgeler            #+#    #+#             */
/*   Updated: 2025/06/03 19:44:45 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_strlcpy(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen_strlcpy(src));
	i = 0;
	while ((i < dstsize - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i += 1;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (ft_strlen_strlcpy(src));
}
