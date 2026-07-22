/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:40:25 by tgeler            #+#    #+#             */
/*   Updated: 2025/06/03 19:40:25 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*dynamic_memory;
	size_t	i;
	size_t	max;

	max = (size_t) - 1;
	if (size != 0 && (nmemb > (max / size)))
		return (NULL);
	i = 0;
	dynamic_memory = (char *)malloc(nmemb * size);
	if (!dynamic_memory)
		return (NULL);
	while (i < (nmemb * size))
	{
		dynamic_memory[i] = '\0';
		i++;
	}
	return ((void *)dynamic_memory);
}
