/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:41:26 by tgeler            #+#    #+#             */
/*   Updated: 2025/06/03 19:41:26 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*just_for_min_int(void)
{
	char	*array;
	char	*ptr;
	size_t	i;

	array = malloc(12);
	if (!array)
		return (NULL);
	array[11] = '\0';
	ptr = "-2147483648";
	i = 0;
	while (i < 11)
	{
		array[i] = ptr[i];
		i++;
	}
	return (array);
}

static char	*extreme_conditions(int n)
{
	char	*array;

	if (n == 0)
	{
		array = malloc(2);
		if (!array)
			return (NULL);
		array[0] = '0';
		array[1] = '\0';
		return (array);
	}
	array = just_for_min_int();
	return (array);
}

static char	*fill_it(char *array, int n, char mode, size_t index)
{
	if (mode == '+')
	{
		while (n / 10 != 0)
		{
			array[index] = (n % 10) + '0';
			n /= 10;
			index--;
		}
		array[index] = (n % 10) + '0';
	}
	if (mode == '-')
	{
		array[0] = '-';
		while (array[index] != '-')
		{
			array[index] = (n % 10) + '0';
			n /= 10;
			index--;
		}
	}
	return (array);
}

static size_t	calculate_size(int n)
{
	size_t	i;

	i = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*array;

	if (n == 0 || n == -2147483648)
		return (extreme_conditions(n));
	if (n < 0 && n != -2147483648)
	{
		n *= (-1);
		size = calculate_size(n);
		array = malloc(sizeof(char) * (size + 2));
		if (!array)
			return (NULL);
		array[size + 1] = '\0';
		return (fill_it(array, n, '-', size));
	}
	if (n > 0)
	{
		size = calculate_size(n);
		array = malloc(sizeof(char) * (size + 1));
		if (!array)
			return (NULL);
		array[size] = '\0';
		return (fill_it(array, n, '+', (size - 1)));
	}
	return (NULL);
}
