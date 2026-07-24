/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 22:36:14 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/21 02:37:29 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "../signals/signals.h"
#include "free_functions/free_functions.h"

void	signal_actions(int *success, t_shell *shell)
{
	shell->last_status = 128 + WTERMSIG(*success);
	if (WTERMSIG(*success) == SIGINT)
		write(1, "\n", 1);
	else if (WTERMSIG(*success) == SIGQUIT)
		write(1, "Quit (core dumped)\n", 19);
}

void	execute_if_dnnp_u(t_shell *shell, t_cmd *command_list, int *success)
{
	pid_t	process_id;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	process_id = fork();
	if (process_id < 0)
		child_couldnt_created(shell);
	else if (process_id == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (does_have_redirections(command_list))
			if_redirection_valid_apply_redir(shell, command_list, 1);
		if (is_valid_command(shell, command_list))
			run_external(command_list, shell);
	}
	else
	{
		waitpid(process_id, success, 0);
		if (WIFEXITED(*success))
			shell->last_status = WEXITSTATUS(*success);
		else if (WIFSIGNALED(*success))
			signal_actions(success, shell);
	}
}

void	execute_if_dnnp(t_shell *shell, t_cmd *command_list, int builtin_nbr)
{
	int		success;

	success = 0;
	if (builtin_nbr > 0)
	{
		if (does_have_redirections(command_list))
		{
			success = apply_redirections(command_list, shell, 0);
			if (success == 0)
				return (set_keyboard_and_screen(shell));
		}
		run_builtin(command_list, shell, builtin_nbr, 0);
	}
	else
		execute_if_dnnp_u(shell, command_list, &success);
}

void	execute_it(t_cmd *command_list, t_shell *shell)
{
	int		builtin_nbr;

	builtin_nbr = 0;
	if (heredoc_pre_process(shell, command_list, 0) == 0)
		return (set_keyboard_and_screen(shell));
	if (command_list->argc > 0)
		builtin_nbr = is_builtin_which(command_list->argv[0]);
	if (does_need_pipe(command_list, builtin_nbr, shell->has_pipe_in_line))
		executor_pipe(command_list, shell, builtin_nbr);
	else
		execute_if_dnnp(shell, command_list, builtin_nbr);
	return (set_keyboard_and_screen(shell));
}
