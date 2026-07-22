/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:43:38 by tgeler            #+#    #+#             */
/*   Updated: 2025/06/03 19:43:38 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	lets_write(int n, int fd)
{
	char	digit;

	if (n >= 10)
		lets_write(n / 10, fd);
	digit = (n % 10) + '0';
	write(fd, &digit, 1);
}

static void	extreme_conditions(int n, int fd)
{
	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else
		write(fd, "0", 1);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	char	sign;

	sign = '-';
	if (n == 0 || n == -2147483648)
		extreme_conditions(n, fd);
	else if (n > 0 || n < 0)
	{
		if (n < 0)
		{
			write(fd, &sign, 1);
			n *= -1;
		}
		lets_write(n, fd);
		return ;
	}
	return ;
}
