/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:42:00 by tgeler            #+#    #+#             */
/*   Updated: 2025/06/03 19:42:00 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*temp_ptr;

	temp_ptr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (temp_ptr[i] == (unsigned char)c)
			return ((void *)&temp_ptr[i]);
		i++;
	}
	return (NULL);
}
