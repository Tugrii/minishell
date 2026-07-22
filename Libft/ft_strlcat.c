/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:44:31 by tgeler            #+#    #+#             */
/*   Updated: 2025/06/03 19:44:31 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_strlcat(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	length_src;
	size_t	length_dst;
	size_t	i;

	i = 0;
	length_dst = ft_strlen_strlcat(dst);
	length_src = ft_strlen_strlcat(src);
	if (dstsize <= length_dst)
		return (dstsize + length_src);
	while ((src[i] != '\0') && ((length_dst + i) < dstsize - 1))
	{
		dst[length_dst + i] = src[i];
		i++;
	}
	dst[length_dst + i] = '\0';
	return (length_dst + length_src);
}
