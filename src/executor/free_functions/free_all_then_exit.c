/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 20:25:52 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/21 00:17:23 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"
#include "free_functions.h"

void	free_env_list(t_shell *shell, int mode, int exit_code)
{
	t_env	*temp_env;

	while (shell->env)
	{
		temp_env = (shell->env)->next;
		free((shell->env)->key);
		free((shell->env)->value);
		free(shell->env);
		shell->env = temp_env;
	}
	if (mode == 1)
		exit(exit_code);
}

void	free_all_then_exit_utils(t_shell *shell, int exit_code)
{
	t_token	*temp_token;

	free_env_list(shell, 0, 0);
	while (shell->token)
	{
		temp_token = (shell->token)->next;
		free(shell->token->text);
		free (shell->token);
		shell->token = temp_token;
	}
	shell->last_status = exit_code;
	close_all_fds(shell, 0);
	exit(exit_code);
}

void	free_all_then_exit(t_shell *shell, int exit_code)
{
	t_cmd	*temp_cmd;
	t_redir	*temp_redir;
	int		i;

	while (shell->cmd)
	{
		i = 0;
		temp_cmd = (shell->cmd)->next;
		while (i < (shell->cmd)->argc)
		{
			free ((shell->cmd)->argv[i]);
			i++;
		}
		free(shell->cmd->argv);
		while (shell->cmd->redirs)
		{
			temp_redir = (shell->cmd->redirs)->next;
			free (((shell->cmd)->redirs)->target);
			free (shell->cmd->redirs);
			shell->cmd->redirs = temp_redir;
		}
		free(shell->cmd);
		shell->cmd = temp_cmd;
	}
	free_all_then_exit_utils(shell, exit_code);
}

void	malloc_error(t_shell *shell, char *str1)
{
	free(str1);
	perror("minishell: ");
	if (shell)
		free_all_then_exit(shell, 1);
	else
		exit(1);
}
