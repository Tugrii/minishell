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
void	lets_work_the_child(int i, exec_infos *executor, int prev_fd)
{
	if (i > 0)
	{
		dup2(prev_fd, 0);
		close(prev_fd);
	}

	if (i < (executor->cmd_count - 1))
		dup2(executor->fds[1], 1);
	close_related_fds(executor->fds[0], executor->fds[1], 'n');
}

void	execute(exec_infos *executor)
{
	int		i;
	int		prev_fd;
	int		j;

	j = 0;
	i = 0;
	prev_fd = -1;
	executor->pids = malloc(executor->cmd_count * sizeof(pid_t));
	if (!(executor->pids))
		exec_error(1, "Malloc Error!", 'm', executor);
	while (i < executor->cmd_count)
	{
		if (i < executor->cmd_count - 1)
			pipe(executor->fds);
		executor->pids[i] = fork();
		if (executor->pids[i] == -1)
			close_related_fds(executor->fds[0], executor->fds[1], 'e');
		if (executor->pids[i] == 0)
			lets_work_the_child(i, executor, prev_fd);
		if (prev_fd != -1)
			close (prev_fd);
		if ((i < executor->cmd_count - 1) && executor->pids[i] != -1)
		{
			close(executor->fds[1]);
			prev_fd = executor->fds[0];
		}
		i++;
	}
	while (j < i)
	{
		waitpid(executor->pids[j], NULL, 0);
		j++;
	}
}

