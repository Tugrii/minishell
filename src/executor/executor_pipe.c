/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 01:09:26 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/21 03:29:38 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "free_functions/free_functions.h"

void	executor_pipe_last_check(t_shell *shell, pid_t last_pid)
{
	int	raw_status;

	if (last_pid > 0)
	{
		waitpid(last_pid, &raw_status, 0);
		if (WIFEXITED(raw_status))
			shell->last_status = WEXITSTATUS(raw_status);
		else if (WIFSIGNALED(raw_status))
			shell->last_status = 128 + WTERMSIG(raw_status);
	}
	while (wait(NULL) > 0)
		;
}

pid_t	executor_pipe_parent(t_shell *shell, pid_t process_id)
{
	pid_t	last_pid;

	last_pid = process_id;
	if (shell->next_fds[1] != -1)
	{
		close(shell->next_fds[1]);
		shell->next_fds[1] = -1;
	}
	if (shell->old_fd != -1)
	{
		close(shell->old_fd);
		shell->old_fd = -1;
	}
	shell->old_fd = shell->next_fds[0];
	shell->next_fds[0] = -1;
	return (last_pid);
}

void	executor_pipe_child(t_shell *shell,
		t_cmd *traversal_cmd, int builtin_nbr)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (shell->old_fd > 0)
	{
		dup2(shell->old_fd, 0);
		close(shell->old_fd);
	}
	if (traversal_cmd->next)
	{
		close(shell->next_fds[0]);
		dup2(shell->next_fds[1], 1);
		close(shell->next_fds[1]);
	}
	close_all_fds(shell, 1);
	if (does_have_redirections(traversal_cmd))
		if_redirection_valid_apply_redir(shell, traversal_cmd, 1);
	if (is_valid_command(shell, traversal_cmd))
	{
		if (builtin_nbr > 0)
			run_builtin(traversal_cmd, shell, builtin_nbr, 1);
		else
			run_external(traversal_cmd, shell);
	}
}

t_cmd	*executor_pipe(t_cmd *command_list, t_shell *shell, int builtin_nbr)
{
	pid_t	process_id;
	t_cmd	*traversal_cmd;
	pid_t	last_pid;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	traversal_cmd = command_list;
	while (traversal_cmd)
	{
		shell->has_pipe_in_line = 1;
		is_not_last_command_open_pipe(shell, traversal_cmd);
		process_id = fork();
		if (process_id < 0)
			child_couldnt_created(shell);
		else if (process_id == 0)
			executor_pipe_child(shell, traversal_cmd, builtin_nbr);
		else
			last_pid = executor_pipe_parent(shell, process_id);
		traversal_cmd = traversal_cmd->next;
		if (traversal_cmd && traversal_cmd->argc > 0)
			builtin_nbr = is_builtin_which(traversal_cmd->argv[0]);
	}
	executor_pipe_last_check(shell, last_pid);
	return (traversal_cmd);
}
