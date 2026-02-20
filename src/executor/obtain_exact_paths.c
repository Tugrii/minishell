/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obtain_exact_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 20:29:25 by tgeler            #+#    #+#             */
/*   Updated: 2026/02/03 20:29:25 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static char	*if_accesible_return_exact_path(char *command, exec_infos *executor)
{
	char	*temp;
	int		i;

	i = 0;
	if (ft_strchr(command, '/') && access(command, 0) == 0)
		return (ft_strdup(command));
	while (executor->path_list[i])
	{
		temp = ft_strjoin(executor->path_list[i], command);
		if (!temp)
			exec_error(1, "Malloc Error!", 'm', executor);
		if (access(temp, 0) == 0)
			return (temp);
		else
			free (temp);
		i++;
	}
	return (NULL);
}

int	calculate_command_count(char ***commands)
{
	int	i;

	i = 0;
	while (commands[i])
		i++;
	return (i);
}

static int	check_is_builtin(char *command)
{
	char	*built_ins[8];
	int		i;

	i = 0;
	built_ins[0] = "echo";
	built_ins[1] = "cd";
	built_ins[2] = "pwd";
	built_ins[3] = "export";
	built_ins[4] = "unset";
	built_ins[5] = "env";
	built_ins[6] = "exit";
	while (i < 7)
	{
		if (ft_strncmp(command, built_ins[i], ft_strlen(built_ins[i]) + 1) == 0)
			return (1);
		i++;
	}
	return (0);
}

static void	add_sign_to_paths(exec_infos *executor)
{
	int		i;
	char	*temp;

	i = 0;
	while (executor->path_list[i])
	{
		temp = ft_strjoin(executor->path_list[i], "/");
		if (!temp)
			exec_error(1, "Malloc Error!", 'm', executor);
		free (executor->path_list[i]);
		executor->path_list[i] = temp;
		i++;
	}
}

char	**obtain_exact_paths(exec_infos *executor)
{
	int		i;

	i = 0;
	add_sign_to_paths(executor);
	executor->exact_path_list = (char **)malloc((executor->cmd_count + 1) * sizeof(char *));
	if (!executor->exact_path_list)
		exec_error(1, "Malloc Error!", 'm', executor);
	executor->exact_path_list[executor->cmd_count] = NULL;
	while (i < executor->cmd_count)
	{
		if (check_is_builtin(executor->commands[i][0]) == 1)
			executor->exact_path_list[i] = NULL;
		else
			executor->exact_path_list[i] = if_accesible_return_exact_path(executor->commands[i][0],
					executor);
		i++;
	}
	return (executor->exact_path_list);
}
