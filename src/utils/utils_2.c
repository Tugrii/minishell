/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:59:44 by fatmdemi          #+#    #+#             */
/*   Updated: 2026/07/18 18:03:27 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

void	fatal_alloc(const char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

size_t	ms_strlen(const char *s)
{
	return (ft_strlen(s));
}

char	*ms_strdup(const char *s)
{
	return (ft_strdup(s));
}

int	ms_strcmp(const char *s1, const char *s2)
{
	unsigned char	c1;
	unsigned char	c2;

	while (*s1 || *s2)
	{
		c1 = (unsigned char)*s1;
		c2 = (unsigned char)*s2;
		if (c1 != c2)
			return ((int)c1 - (int)c2);
		if (*s1)
			s1++;
		if (*s2)
			s2++;
	}
	return (0);
}
