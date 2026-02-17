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

void	execute(exec_infos *minishell)
{
	int		i;
	int		command_count;

	i = 0;
	command_count = calculate_command_count(minishell->commands);
	minishell->child_pids = malloc(command_count * sizeof(pid_t));
	if (!(minishell->child_pids))
		exec_error(1, "Malloc Error!", 'm', minishell);
	while (i < command_count)
	{
		
		child_pids[i] = fork();
	}
}
