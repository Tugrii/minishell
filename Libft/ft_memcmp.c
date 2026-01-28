/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:50:59 by tgeler            #+#    #+#             */
/*   Updated: 2025/06/01 15:50:59 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_c;
	unsigned char	*s2_c;
	size_t			i;

	i = 0;
	s1_c = (unsigned char *) s1;
	s2_c = (unsigned char *) s2;
	while (i < n)
	{
		if (!(s1_c[i] == s2_c[i]))
			return ((int)(s1_c[i] - s2_c[i]));
		i++;
	}
	return (0);
}
