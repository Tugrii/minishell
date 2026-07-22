/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 22:34:06 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/06 17:11:04 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	does_need_pipe(t_cmd *command_list, int builtin_nbr, int has_pipe_in_line)
{
	if (has_pipe_in_line && builtin_nbr == 7)
		return (1);
	if (command_list && (command_list->next != NULL))
		return (1);
	return (0);
}

void	set_keyboard_and_screen(t_shell *shell)
{
	dup2(shell->orig_stdin, 0);
	dup2(shell->orig_stdout, 1);
}
