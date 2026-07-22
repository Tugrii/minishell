/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 03:24:39 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/21 03:24:39 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "free_functions/free_functions.h"

int	is_valid_command(t_shell *shell, t_cmd *command_list)
{
	if (command_list->argc > 0 && command_list->argv && command_list->argv[0])
		return (1);
	else
		free_all_then_exit(shell, 0);
	return (0);
}

void	if_redirection_valid_apply_redir(t_shell *shell, t_cmd *command_list,
	int is_child)
{
	if (!apply_redirections(command_list, shell, is_child))
		free_all_then_exit(shell, 1);
}

void	is_not_last_command_open_pipe(t_shell *shell, t_cmd *cmd)
{
	if (cmd->next)
	{
		if (pipe(shell->next_fds) == -1)
			pipe_couldnt_created(shell);
	}
	else
	{
		shell->next_fds[0] = -1;
		shell->next_fds[1] = -1;
	}
}
