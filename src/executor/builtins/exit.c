/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 21:13:27 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/20 17:01:39 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	set_then_close_keyboard_and_screen(t_shell *shell)
{
	dup2(shell->orig_stdin, 0);
	dup2(shell->orig_stdout, 1);
	close(shell->orig_stdin);
	close(shell->orig_stdout);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_exit_status(t_cmd *command_list)
{
	if (!command_list->argv[1])
		return (1);
	else if (command_list->argv[1] && command_list->argv[1][0] == '\0')
		return (2);
	else if (command_list->argv[1] && !is_number(command_list->argv[1]))
		return (3);
	else if (command_list->argv[1] && command_list->argv[2])
		return (4);
	return (5);
}

void	run_exit(t_cmd *command_list, t_shell *shell)
{
	int	status;

	set_then_close_keyboard_and_screen(shell);
	status = check_exit_status(command_list);
	if (status == 1)
		exit(shell->last_status);
	else if (status == 2)
	{
		print_error_msg_exit(NULL, 1);
		exit(2);
	}
	else if (status == 3)
	{
		print_error_msg_exit(command_list->argv[1], 1);
		exit(2);
	}
	else if (status == 4)
	{
		print_error_msg_exit(NULL, 2);
		shell->last_status = 1;
	}
	else
		exit(ft_atoi(command_list->argv[1]) % 256);
}
