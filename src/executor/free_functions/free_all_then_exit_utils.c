/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_then_exit_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 00:10:46 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/21 00:18:34 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	close_all_fds(t_shell *shell, int mode)
{
	if (mode == 1)
	{
		if (shell->next_fds[0] >= 0)
		{
			close(shell->next_fds[0]);
			shell->next_fds[0] = -1;
		}
		if (shell->next_fds[1] >= 0)
		{
			close(shell->next_fds[1]);
			shell->next_fds[1] = -1;
		}
		return ;
	}
	if (shell->orig_stdin >= 0)
	{
		close(shell->orig_stdin);
		shell->orig_stdin = -1;
	}
	if (shell->orig_stdout >= 0)
	{
		close(shell->orig_stdout);
		shell->orig_stdout = -1;
	}
}
