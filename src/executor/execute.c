/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 21:31:11 by tgeler            #+#    #+#             */
/*   Updated: 2026/02/05 21:31:11 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	close_related_fds(int fdin, int fdout, char mode)
{
	if (mode == 'e')
		perror("Fork Error!");
	close(fdin);
	close(fdout);
}
void	lets_work_the_child(int i, exec_infos *executor)
{
	if (i == 0)
	{
		dup2(executor->fds[0], 0);
		dup2(executor->fds[1], 1);
	}
	else
	{

	}
	close_related_fds(executor->fds[0], executor->fds[1], 'n');
	execve(executor->exact_path_list[i], executor->commands[i], executor->envp);
}

void	execute(exec_infos *executor)
{
	int		i;
	int		prev_fd;

	i = 0;
	executor->pids = malloc(executor->cmd_count * sizeof(pid_t));
	if (!(executor->pids))
		exec_error(1, "Malloc Error!", 'm', executor);
	while (i < executor->cmd_count)
	{
		pipe(executor->fds);
		executor->pids[i] = fork();
		if (executor->pids[i] == -1)
			close_related_fds(executor->fds[0], executor->fds[1], 'e');
		if (executor->pids[i] == 0)
			lets_work_the_child(i, executor);
		i++;
	}
}

