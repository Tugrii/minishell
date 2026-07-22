/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:38:00 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/21 03:58:53 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Libft/libft.h"
#include "../../include/minishell.h"
#include "builtins/builtins.h"
#include "external/external.h"
#include "redirections/redirections.h"

void	execute_it(t_cmd *command_list, t_shell *shell);
int		does_need_pipe(t_cmd *command_list, int builtin_nbr,
			int has_pipe_in_line);
void	pipe_couldnt_created(t_shell *shell);
void	child_couldnt_created(t_shell *shell);
void	set_keyboard_and_screen(t_shell *shell);
t_cmd	*executor_pipe(t_cmd *command_list, t_shell *shell, int builtin_nbr);
int		is_valid_command(t_shell *shell, t_cmd *command_list);
void	if_redirection_valid_apply_redir(t_shell *shell, t_cmd *command_list,
			int is_child);
void	is_not_last_command_open_pipe(t_shell *shell, t_cmd *cmd);