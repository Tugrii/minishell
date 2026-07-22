/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 16:20:53 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 17:32:42 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

int	heredoc_cancelled(void)
{
	signal_initilaze();
	return (0);
}

int	heredoc_pre_process(t_shell *shell, t_cmd *command_list, int command_no)
{
	t_redir	*traversal_redir;
	t_cmd	*traversal_cmd;
	int		redir_no;

	heredoc_signal_initilaze();
	traversal_cmd = command_list;
	while (traversal_cmd)
	{
		traversal_redir = traversal_cmd->redirs;
		redir_no = 0;
		while (traversal_redir)
		{
			if (traversal_redir->type == RD_HEREDOC)
				if (!create_temp_file_then_write(shell, traversal_redir,
						command_no, redir_no))
					return (heredoc_cancelled());
			redir_no++;
			traversal_redir = traversal_redir->next;
		}
		command_no++;
		traversal_cmd = traversal_cmd->next;
	}
	signal_initilaze();
	return (1);
}
