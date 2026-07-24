/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_over_limit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/19 19:27:08 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Libft/libft.h"

static int	check_overflow(unsigned long long res, int sign, char digit)
{
	unsigned long long	max;

	max = 9223372036854775807ULL;
	if (sign == -1)
		max = 9223372036854775808ULL;
	if (res > max / 10)
		return (1);
	if (res == max / 10 && (unsigned long long)(digit - '0') > (max % 10))
		return (1);
	return (0);
}

int	parse_exit_number(char *str, long long *result, int i, int sign)
{
	unsigned long long	tmp;

	tmp = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
	{
		if (check_overflow(tmp, sign, str[i]))
			return (0);
		tmp = (tmp * 10) + (str[i++] - '0');
	}
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i])
		return (0);
	*result = (long long)tmp * sign;
	return (1);
}
