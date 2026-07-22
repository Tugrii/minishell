/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 10:42:58 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 02:57:14 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../free_functions/free_functions.h"

int	cd_error_msg(int msg_nbr, t_shell *shell)
{
	if (msg_nbr == 1)
		write(2, "minishell: cd: too many arguments \n", 36);
	if (msg_nbr == 2)
		perror("minishell: cd");
	shell->last_status = 1;
	return (0);
}

int	check_cd(t_cmd *command_list, t_shell *shell)
{
	if (command_list->argv[1] && command_list->argv[2] != NULL)
		return (cd_error_msg(1, shell));
	return (1);
}

int	check_getcwd_set_env(char **current_pwd, char *old_pwd,
		t_shell *shell, int mode)
{
	if (mode == 1)
	{
		if (!old_pwd)
			return (cd_error_msg(2, shell));
	}
	if (mode == 2)
	{
		if (!(*current_pwd))
			return (cd_error_msg(2, shell));
		env_set(&(shell->env), "OLDPWD", old_pwd, 1);
		env_set(&(shell->env), "PWD", *current_pwd, 1);
		free (*current_pwd);
		*current_pwd = NULL;
	}
	return (1);
}

void	run_cd(t_cmd *command_list, t_shell *shell)
{
	t_cd	cd;
	int		flag;

	flag = 0;
	cd.target = command_list->argv[1];
	if (cd.target && cd.target[0] == '\0')
		return ;
	if (check_cd(command_list, shell))
	{
		cd.old_pwd = getcwd(NULL, 0);
		check_getcwd_set_env(&(cd.current_pwd), cd.old_pwd, shell, 1);
		if (cd.target == NULL || (cd.target && cd.target[0] == '~'))
			cd.target = set_home(shell, command_list, &flag);
		else if (cd.target && cd.target[0] == '-')
			cd.target = set_old_pwd_print_pwd(shell, &flag);
		if (!(cd.target))
			return (oldpwd_error(shell, cd.old_pwd));
		if (chdir(cd.target) == 0)
			change_directory(shell, cd.old_pwd, &(cd.current_pwd));
		else
			cd_error_msg(2, shell);
		if (flag == 1 || flag == 2)
			flag_triggered(flag, cd.target, cd.old_pwd);
		free(cd.old_pwd);
	}
}
