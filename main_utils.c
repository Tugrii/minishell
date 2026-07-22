/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 22:20:13 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/20 23:50:28 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"
#include "src/executor/free_functions/free_functions.h"

void	free_token(t_token *token)
{
	t_token	*temp_token;

	while (token)
	{
		temp_token = token->next;
		free(token->text);
		token->text = NULL;
		free(token);
		token = temp_token;
	}
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*temp_cmd;
	t_redir	*temp_redir;
	int		i;

	while (cmd)
	{
		i = 0;
		temp_cmd = cmd->next;
		while (i < cmd->argc)
		{
			free(cmd->argv[i]);
			i++;
		}
		free (cmd->argv);
		while (cmd->redirs)
		{
			temp_redir = cmd->redirs->next;
			free (cmd->redirs->target);
			free (cmd->redirs);
			cmd->redirs = temp_redir;
		}
		free(cmd);
		cmd = temp_cmd;
	}
}

void	loop_ended(t_shell *shell)
{
	close(shell->orig_stdin);
	close(shell->orig_stdout);
	free_env_list(shell, 1, 0);
}

void	set_signal_if_pressed_ctrl_c(t_shell *shell)
{
	if (g_signal_status == 130)
	{
		shell->last_status = 130;
		g_signal_status = 0;
	}
}
