/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 21:31:11 by tgeler            #+#    #+#             */
/*   Updated: 2026/02/05 21:31:11 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	execute(path_info *minishell)
{
	int		i;
	int		command_count;

	i = 0;
	command_count = calculate_command_count(minishell->commands);
	minishell->child_pids = malloc(command_count * sizeof(pid_t));
	if (!(minishell->child_pids))
		MALLOC_ERROR!
	while (i < command_count)
	{
		
		child_pids[i] = fork();
	}
}
