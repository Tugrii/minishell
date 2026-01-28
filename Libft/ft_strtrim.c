/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:45:58 by tgeler            #+#    #+#             */
/*   Updated: 2025/06/03 19:45:58 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	can_not_trim(char const *s1, char const *the_trimmed_item)
{
	size_t	i;
	size_t	j;
	size_t	length;
	size_t	count;

	length = ft_strlen(s1);
	i = 0;
	count = 0;
	while (s1[i])
	{
		j = 0;
		while (the_trimmed_item[j])
		{
			if (s1[i] == the_trimmed_item[j])
			{
				count++;
				break ;
			}
			j++;
		}
		i++;
	}
	if (count == length)
		return (1);
	return (0);
}

static size_t	trim_from_back(char const *s1, char const *the_trimmed_item,
	size_t last_index)
{
	size_t	i;
	size_t	j;

	i = last_index;
	while (i > 0)
	{
		j = 0;
		while (the_trimmed_item[j] != '\0')
		{
			if (s1[i] == the_trimmed_item[j])
				break ;
			j++;
		}
		if (s1[i] == the_trimmed_item[j])
			i--;
		else
			return (i);
	}
	return (0);
}

static size_t	trim_from_front(char const *s1, char const *the_trimmed_item)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (the_trimmed_item[j] != '\0')
		{
			if (s1[i] == the_trimmed_item[j])
				break ;
			j++;
		}
		if (s1[i] == the_trimmed_item[j])
			i++;
		else
			return (i);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		first_index;
	char		*dynamic;
	size_t		last_index;
	size_t		i;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	if (can_not_trim(s1, set) == 1)
		return (ft_strdup(""));
	first_index = trim_from_front(s1, set);
	last_index = trim_from_back(s1, set, ft_strlen(s1) - 1);
	dynamic = malloc(sizeof(char) * (last_index - first_index + 2));
	if (!dynamic)
		return (NULL);
	i = 0;
	while (first_index <= last_index)
	{
		dynamic[i] = s1[first_index];
		first_index++;
		i++;
	}
	dynamic[i] = '\0';
	return (dynamic);
}
