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

static int	check_is_over_limit_utils(int last_index, char *str, int sign)
{
	long long	result;
	long long	calc;
	int			len;

	len = ft_strlen(str);
	result = 0;
	result += str[last_index] - '0';
	calc = 10;
	last_index--;
	if ((str[0] == '-' || str[0] == '+') && len > 11)
		return (1);
	else if (len > 10 && !(str[0] == '-' || str[0] == '+'))
		return (1);
	while (last_index != -1
		&& !(str[last_index] == '-' || str[last_index] == '+'))
	{
		result += calc * (str[last_index] - '0');
		calc *= 10;
		last_index--;
	}
	result *= sign;
	if ((result >= -2147483648 && result <= 2147483647))
		return (0);
	return (1);
}

int	check_is_over_lim(char *str)
{
	int			i;
	int			sign;
	int			last_index;

	i = 0;
	while (str[i])
	{
		last_index = ft_strlen(str) - 1;
		sign = 1;
		if (str[0] == '-' || str[0] == '+')
		{
			if (str[0] == '-')
				sign = -1;
		}
		if (check_is_over_limit_utils(last_index, str, sign))
			return (1);
		i++;
	}
	return (0);
}
