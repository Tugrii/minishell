/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 14:55:04 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/04 17:46:19 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	pipe_couldnt_created(t_shell *shell)
{
	perror("pipe");
	close(shell->old_fd);
	shell->last_status = 1;
}

void	child_couldnt_created(t_shell *shell)
{
	perror("fork");
	close(shell->next_fds[0]);
	close(shell->next_fds[1]);
	close(shell->old_fd);
	shell->last_status = 1;
}
