/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_controllers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:42:46 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 03:21:05 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	check_contain_flag(t_cmd *command)
{
	int	j;

	j = 2;
	if (command->argc >= 2 && command->argv[1])
	{
		if (!ft_strncmp(command->argv[0], "echo", 4))
		{
			if (command->argv[1][0] == '-' && command->argv[1][1] == 'n')
			{
				while (command->argv[1][j] != '\0')
				{
					if (command->argv[1][j] == 'n')
						j++;
					else
						break ;
				}
				if (command->argv[1][j] == '\0')
					return (1);
			}
		}
	}
	return (0);
}

int	is_builtin_which(char *command)
{
	int		i;
	char	*builtin_list[7];
	int		command_len;

	i = 0;
	if (command)
	{
		command_len = ft_strlen(command);
		builtin_list[0] = "echo";
		builtin_list[1] = "cd";
		builtin_list[2] = "pwd";
		builtin_list[3] = "export";
		builtin_list[4] = "unset";
		builtin_list[5] = "env";
		builtin_list[6] = "exit";
		while (i < 7)
		{
			command_len = get_bigger_string_len(builtin_list[i], command);
			if ((ft_strncmp(command, builtin_list[i], command_len)) == 0)
				return (i + 1);
			i++;
		}
	}
	return (0);
}
