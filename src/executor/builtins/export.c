/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:40:52 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/14 20:58:29 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	export_contain_flag(t_export *export, char *command, int len, int arg_no)
{
	char	*valid_flags_list;
	int		i;
	int		j;

	i = 1;
	valid_flags_list = "fnpa";
	if (len > 0 && (ft_strncmp(command, "--help", len) == 0
			|| ft_strncmp(command, "--", len) == 0))
		return (sign_and_print_err(export, NULL, 1, arg_no));
	while (command[i] != '\0')
	{
		j = 0;
		while (valid_flags_list[j] != '\0')
		{
			if (command[i] == valid_flags_list[j])
				break ;
			j++;
		}
		if (command[i] == valid_flags_list[j])
			i++;
		else
			return (sign_and_print_err(export, &command[i], 2, arg_no));
	}
	return (sign_and_print_err(export, NULL, 1, arg_no));
}

int	export_is_contain_invalid_char(char *command)
{
	int	i;

	i = 0;
	if (!(command[0] == '_' || ft_isalpha(command[0])))
		return (1);
	else
	{
		while (command[i] != '\0' && command[i] != '=')
		{
			if (!(ft_isalnum(command[i]) || command[i] == '_'))
				return (1);
			i++;
		}
	}
	return (0);
}

int	check_export(t_cmd *command_list, t_export *export, int *err_occured)
{
	int		i;
	int		len;

	i = 1;
	if (command_list->argv[i])
		len = ft_strlen(command_list->argv[i]);
	else
		return (0);
	if ((command_list->argv[1][0] && command_list->argv[1][0] == '-') &&
		(command_list->argv[1][1] && command_list->argv[1][1] != '\0'))
	{
		if (export_contain_flag(export, command_list->argv[i], len, 1) == 2)
			*err_occured = 2;
		i++;
	}
	while (command_list->argv[i])
	{
		if (command_list->argv[i][0] == '\0')
			*err_occured = sign_and_print_err(export, NULL, 3, i);
		else if (export_is_contain_invalid_char(command_list->argv[i]))
			*err_occured = sign_and_print_err(export,
					command_list->argv[i], 3, i);
		i++;
	}
	return (1);
}

void	run_export(t_cmd *command_list, t_shell *shell)
{
	t_export	export;
	int			err_occured;

	err_occured = 0;
	export.state_list = NULL;
	export.shell = shell;
	create_state_list_and_fill(&(export.state_list), command_list);
	if (check_export(command_list, &export, &err_occured))
		run_export_utils(command_list, shell, export.state_list);
	else
		print_export(shell);
	shell->last_status = err_occured;
	free_state_list(&(export.state_list));
	return ;
}
