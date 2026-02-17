/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:11:02 by tgeler            #+#    #+#             */
/*   Updated: 2026/02/17 17:49:32 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Libft/libft.h"
#include <stdio.h>
#include <executor_struct.h>

void free_all_exec_utils1(exec_infos *executor)
{
	int	i;
	int j;

	if (executor->commands)
	{
		i = 0;
		while (executor->commands[i])
		{
			j = 0;
			while (executor->commands[i][j])
			{
				free(executor->commands[i][j]);
				j++;	
			}
			free(executor->commands[i]);
			i++;
		}
		free(executor->commands);
	}
	i = 0;
	
}
void free_all_exec(exec_infos *executor)
{
	int	i;

	if (executor->path_list)
	{
		i = 0;
		while (executor->path_list[i])
		{
			free(executor->path_list[i]);
			i++;
		}
		free(executor->path_list);
	}
	if (executor->exact_path_list)
	{
		i = 0;
		while (i < executor->cmd_count)
		{
			free(executor->exact_path_list[i]);
			i++;
		}
		free(executor->exact_path_list);
	}
	executor->path_list = NULL;
	executor->exact_path_list = NULL;
	free_all_utils1(executor);
}

int	exec_error(int error_num, char *error_message, char process_type,
			exec_infos *executor)
{
	free_all(executor);
	perror(error_message);
	if (process_type == 'c')
		exit(error_num);
}
