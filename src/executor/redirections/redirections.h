/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 22:51:18 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 16:24:43 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int		does_have_redirections(t_cmd *command_list);
int		apply_redirections(t_cmd *command_list, t_shell *shell, int is_child);
int		print_error_then_exit(char *error_msg, t_shell *shell, int is_child);
int		heredoc_pre_process(t_shell *shell, t_cmd *command_list,
			int command_no);
int		apply_rd_in(t_redir *traversal_redir, t_shell *shell, int is_child);
int		apply_rd_out(t_redir *traversal_redir, t_shell *shell, int is_child);
int		apply_rd_append(t_redir *traversal_redir, t_shell *shell, int is_child);
int		apply_rd_heredoc(t_redir *traversal_redir, t_shell *shell, int is_child);