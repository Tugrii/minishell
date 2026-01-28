/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:45:25 by tgeler            #+#    #+#             */
/*   Updated: 2025/06/03 19:45:25 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_strnstr(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	matched_counter(const char *haystack, const char *needle,
size_t i, size_t len)
{
	size_t	j;
	int		matched;
	size_t	ndl_len;

	ndl_len = ft_strlen_strnstr(needle);
	matched = 0;
	j = 0;
	while ((j < ndl_len) && (i < len) && haystack[i])
	{
		if (haystack[i] == needle[j])
		{
			matched++;
			i++;
			j++;
		}
		else
			return (0);
	}
	return (matched);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	matched;

	i = 0;
	matched = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] && (i < len))
	{
		if (haystack[i] == needle[0])
			matched = matched_counter(haystack, needle, i, len);
		if (matched == ft_strlen_strnstr(needle))
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
