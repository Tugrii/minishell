/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:40:17 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 17:44:21 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"
#include "redirections.h"

int	does_have_redirections(t_cmd *command_list)
{
	if (command_list && command_list->redirs)
		return (1);
	return (0);
}

int	apply_redirections(t_cmd *command_list, t_shell *shell, int is_child)
{
	t_redir	*traversal_redir;
	int		success;

	traversal_redir = command_list->redirs;
	while (traversal_redir)
	{
		success = 1;
		if (traversal_redir->type == RD_IN)
			success = apply_rd_in(traversal_redir, shell, is_child);
		else if (traversal_redir->type == RD_OUT)
			success = apply_rd_out(traversal_redir, shell, is_child);
		else if (traversal_redir->type == RD_APPEND)
			success = apply_rd_append(traversal_redir, shell, is_child);
		else if (traversal_redir->type == RD_HEREDOC)
			success = apply_rd_heredoc(traversal_redir, shell, is_child);
		if (!success)
			return (0);
		traversal_redir = traversal_redir->next;
	}
	return (1);
}
