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

int	check_exit_status(t_cmd *command_list, long long *exit_val)
{
	if (!command_list->argv[1])
		return (1);
	else if (command_list->argv[1] && command_list->argv[1][0] == '\0')
		return (2);
	else if (parse_exit_number(command_list->argv[1], exit_val, 0, 1) == 0)
		return (3);
	else if (command_list->argv[1] && command_list->argv[2])
		return (4);
	return (5);
}

void	run_exit(t_cmd *command_list, t_shell *shell)
{
	int			status;
	long long	exit_val;

	exit_val = 0;
	set_then_close_keyboard_and_screen(shell);
	status = check_exit_status(command_list, &exit_val);
	if (status == 1)
		exit(shell->last_status);
	else if (status == 2 || status == 3)
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
		exit((unsigned char)exit_val);
}
