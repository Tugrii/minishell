/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 18:32:06 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/20 00:41:28 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	sign_flag_finished(char *str, int len, int *flag_finished)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (str[0] == '-')
		{
			if (str[i] != 'n')
			{
				*flag_finished = 1;
			}
		}
		else
			*flag_finished = 1;
		i++;
	}
}

void	run_echo_with_flag(t_cmd *command_list, t_shell *shell)
{
	int	i;
	int	len;
	int	flag_finished;

	i = 2;
	flag_finished = 0;
	while (command_list->argv[i])
	{
		len = ft_strlen(command_list->argv[i]);
		if (!flag_finished)
			sign_flag_finished(command_list->argv[i], len, &flag_finished);
		if (flag_finished)
		{
			write(1, command_list->argv[i], len);
			if (command_list->argv[i + 1])
				write(1, " ", 1);
		}
		i++;
	}
	shell->last_status = 0;
}

void	run_echo_without_flag(t_cmd *command_list, t_shell *shell)
{
	int	i;
	int	len;

	i = 1;
	while (command_list->argv[i])
	{
		len = ft_strlen(command_list->argv[i]);
		write(1, command_list->argv[i], len);
		if (command_list->argv[i + 1])
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
	shell->last_status = 0;
}
