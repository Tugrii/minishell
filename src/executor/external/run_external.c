/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_external.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:54:55 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 17:53:42 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_process/path_process.h"
#include "../free_functions/free_functions.h"

char	**list_to_array_utils(t_shell *shell, char **argv)
{
	int		i;
	char	*temp;
	char	*joined_str;
	t_env	*traversal_env;

	traversal_env = shell->env;
	i = 0;
	while (traversal_env)
	{
		temp = ft_strjoin(traversal_env->key, "=");
		if (!temp)
			malloc_error(shell, NULL);
		joined_str = ft_strjoin(temp, traversal_env->value);
		if (!joined_str)
			malloc_error(shell, temp);
		free (temp);
		argv[i] = joined_str;
		traversal_env = traversal_env->next;
		i++;
	}
	return (argv);
}

char	**list_to_array(t_shell *shell)
{
	t_env	*traversal_env;
	char	**argv;
	int		i;

	i = 0;
	traversal_env = shell->env;
	while (traversal_env)
	{
		traversal_env = traversal_env->next;
		i++;
	}
	argv = (char **)malloc(sizeof(char *) * (i + 1));
	if (!argv)
		malloc_error(shell, NULL);
	argv[i] = NULL;
	return (list_to_array_utils(shell, argv));
}

void	run_external(t_cmd *command_list, t_shell *shell)
{
	t_temp	strs;

	strs.env_array = list_to_array(shell);
	strs.splitted_path_list = path_finder(shell->env);
	strs.exact_path = path_creater(strs.splitted_path_list,
			command_list->argv[0]);
	if (!strs.exact_path || command_list->argv[0][0] == '\0')
	{
		ft_putstr_fd(command_list->argv[0], 2);
		ft_putendl_fd(": command not found", 2);
		free_external_temps(&strs);
		free_all_then_exit(shell, 127);
	}
	if (execve(strs.exact_path, command_list->argv, strs.env_array) == -1)
		print_external_error_then_exit(command_list->argv[0], &strs, shell);
	free_external_temps(&strs);
}
