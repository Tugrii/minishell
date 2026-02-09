/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obtain_exact_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 20:29:25 by tgeler            #+#    #+#             */
/*   Updated: 2026/02/03 20:29:25 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Libft/libft.h"

static char	*if_accesible_return_exact_path(char *command, char **path_list)
{
	char	*temp;
	int		i;

	i = 0;
	while (path_list[i])
	{
		if (ft_strchr(command, '/'))
			return (command);
		temp = ft_strjoin(path_list[i], command);
		if (access(temp, 0) == 0)
			return (temp);
		else
			free (temp);
		i++;
	}
	return (NULL);
}

static int	calculate_command_counts(char **commands)
{
	int	i;

	i = 0;
	while (commands[i])
		i++;
	return (i);
}

static int	check_is_builtin(char *command)
{
	char	**built_ins;
	int		i;

	i = 0;
	built_ins = {"echo", "cd", "pwd", "export", "unset", "env", "exit"};
	while (i < 7)
	{
		if (ft_strncmp(command, built_ins[i], ft_strlen(command)) == 0)
			return (1);
		i++;
	}
	return (0);
}

static void	add_sign_to_paths(char ***path_list)
{
	int		i;
	char	*temp;

	i = 0;
	while (*path_list[i])
	{
		temp = ft_strjoin(*path_list[i], '/');
		free (*path[i]);
		*path_list[i] = temp;
		i++;
	}
}

char	**obtain_exact_paths(char **path_list, char **commands)
{
	char	**exact_path_list;
	int		command_count;
	int		i;

	i = 0;
	add_sign_to_paths(path_list);
	command_count = calculate_command_count(commands);
	exact_path_list = (char **)malloc((command_count + 1) * sizeof(char *));
	if (!exact_path_list)
		MALLOC_ERROR!!
	exact_path_list[command_count] = NULL;
	while (i < command_count)
	{
		if (check_is_builtin(commands[i]) == 1)
			exact_path_list[i] = NULL;
		else
			exact_path_list[i] = if_accesible_return_exact_path(commands[i],
					path_list);
		i++;
	}
	return (exact_path_list);
}
