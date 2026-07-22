/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 02:12:14 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/19 04:03:29 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../free_functions/free_functions.h"

char	*set_home(t_shell *shell, t_cmd *command_list, int *flag)
{
	char	*target;

	target = env_get(shell->env, "HOME");
	if (command_list->argv[1] && command_list->argv[1][1] != '\0')
	{
		target = ft_strjoin(target, &(command_list->argv[1][1]));
		if (!target)
			malloc_error(shell, NULL);
		*flag = 1;
	}
	return (target);
}

void	change_directory(t_shell *shell, char *old_pwd, char **current_pwd)
{
	shell->last_status = 0;
	*current_pwd = getcwd(NULL, 0);
	check_getcwd_set_env(current_pwd, old_pwd, shell, 2);
}

char	*set_old_pwd_print_pwd(t_shell *shell, int *flag)
{
	char	*target;

	target = env_get(shell->env, "OLDPWD");
	*flag = 2;
	return (target);
}

void	flag_triggered(int flag, char *target, char *old_pwd)
{
	char	*check_pwd;
	int		len;

	if (flag == 1)
		free(target);
	if (flag == 2)
	{
		check_pwd = getcwd(NULL, 0);
		len = get_bigger_string_len(check_pwd, old_pwd);
		if (check_pwd && old_pwd && ft_strncmp(check_pwd, old_pwd, len) != 0)
			ft_putendl_fd(target, 1);
		free(check_pwd);
	}
}
