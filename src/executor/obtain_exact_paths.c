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
	if (ft_strchr(command, '/') && access(command, 0) == 0)
		return (ft_strdup(command));
	while (path_list[i])
	{
		temp = ft_strjoin(path_list[i], command);
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

static void	add_sign_to_paths(char **path_list)
{
	int		i;
	char	*temp;

	i = 0;
	while (path_list[i])
	{
		temp = ft_strjoin(path_list[i], "/");
		free (path_list[i]);
		path_list[i] = temp;
		i++;
	}
}

char	**obtain_exact_paths(char **path_list, char ***commands)
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
		if (check_is_builtin(commands[i][0]) == 1)
			exact_path_list[i] = NULL;
		else
			exact_path_list[i] = if_accesible_return_exact_path(commands[i][0],
					path_list);
		i++;
	}
	return (exact_path_list);
}
