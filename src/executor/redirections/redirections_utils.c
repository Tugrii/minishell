/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 15:26:19 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 17:44:52 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"
#include "redirections.h"

int	apply_rd_in(t_redir *traversal_redir, t_shell *shell, int is_child)
{
	int	fd;

	fd = open(traversal_redir->target, O_RDONLY);
	if (fd == -1)
		return (print_error_then_exit(traversal_redir->target,
				shell, is_child));
	dup2(fd, 0);
	close(fd);
	return (1);
}

int	apply_rd_out(t_redir *traversal_redir, t_shell *shell, int is_child)
{
	int	fd;

	fd = open(traversal_redir->target, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (print_error_then_exit(traversal_redir->target,
				shell, is_child));
	dup2(fd, 1);
	close(fd);
	return (1);
}

int	apply_rd_append(t_redir *traversal_redir, t_shell *shell, int is_child)
{
	int	fd;

	fd = open(traversal_redir->target, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (print_error_then_exit(traversal_redir->target,
				shell, is_child));
	dup2(fd, 1);
	close(fd);
	return (1);
}

int	apply_rd_heredoc(t_redir *traversal_redir, t_shell *shell, int is_child)
{
	int	fd;

	fd = open(traversal_redir->target, O_RDONLY);
	if (fd == -1)
		return (print_error_then_exit(traversal_redir->target,
				shell, is_child));
	dup2(fd, 0);
	close(fd);
	unlink(traversal_redir->target);
	return (1);
}
