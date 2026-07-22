/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 10:47:25 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 03:15:04 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../free_functions/free_functions.h"

void	run_builtin_without_flag(t_cmd *command_list, t_shell *shell,
							int builtin_nbr)
{
	if (builtin_nbr == 1)
		run_echo_without_flag(command_list, shell);
	if (builtin_nbr == 2)
		run_cd(command_list, shell);
	if (builtin_nbr == 3)
		run_pwd(shell);
	if (builtin_nbr == 4)
		run_export(command_list, shell);
	if (builtin_nbr == 5)
		run_unset(command_list, shell);
	if (builtin_nbr == 6)
		run_env(shell, command_list);
	if (builtin_nbr == 7)
		run_exit(command_list, shell);
	return ;
}

void	run_builtin(t_cmd *command_list, t_shell *shell,
			int builtin_nbr, int is_child)
{
	int	is_contain_flag;

	is_contain_flag = check_contain_flag(command_list);
	if (is_contain_flag)
		run_echo_with_flag(command_list, shell);
	else
		run_builtin_without_flag(command_list, shell, builtin_nbr);
	if (is_child)
		free_all_then_exit(shell, shell->last_status);
}
