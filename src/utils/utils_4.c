/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:59:44 by fatmdemi          #+#    #+#             */
/*   Updated: 2026/07/18 18:03:27 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

int	ms_isalnum(int c)
{
	return (ft_isalnum(c));
}

int	ms_isname_start(int c)
{
	return (ms_isalpha(c) || c == '_');
}

int	ms_isname_char(int c)
{
	return (ms_isalnum(c) || c == '_');
}

char	*ms_strndup(const char *s, size_t n)
{
	char	*copy;
	size_t	length;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (n < length)
		length = n;
	copy = malloc(length + 1);
	if (!copy)
		fatal_alloc("malloc");
	ft_memcpy(copy, s, length);
	copy[length] = '\0';
	return (copy);
}
