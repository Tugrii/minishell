/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_create_temp_file_utils.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:26:14 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 17:46:26 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

int	pressed_ctrl_c(char *file_name, int fd)
{
	close(fd);
	unlink(file_name);
	free(file_name);
	return (0);
}

void	pressed_ctrl_d(t_redir *redir)
{
	ft_putstr_fd("minishell: warning: here-document ", 2);
	ft_putstr_fd("delimited by end-of-file\n", 2);
	free(redir->target);
}

void	matched_with_word(t_redir *redir, char *line)
{
	free(line);
	free (redir->target);
}

int	set_target_close_fd(t_redir *redir, char *file_name, int fd)
{
	redir->target = file_name;
	close(fd);
	return (1);
}
