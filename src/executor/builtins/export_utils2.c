/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 20:04:52 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 03:37:21 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	fill_it(char *src, char *dst, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return ;
}

void	split_and_add_utils(char *cmd, t_shell *shell, int key_len, int val_len)
{
	char	*key;
	char	*value;

	if (is_new_key(cmd, key_len, shell))
	{
		key = (char *)malloc(sizeof(char) * (key_len + 1));
		if (!key)
			fatal_error("malloc");
		key[key_len] = '\0';
		fill_it(cmd, key, key_len);
		value = (char *)malloc(sizeof(char) * (val_len + 1));
		if (!value)
			fatal_error("malloc");
		value[val_len] = '\0';
		fill_it(cmd + key_len + 1, value, val_len);
		env_add_back(&(shell->env), env_new(key, value, 1));
	}
	else
		change_the_value_of_key(shell, cmd, key_len);
}

void	split_and_add(char *cmd, t_shell *shell)
{
	char	*temp;
	int		key_len;
	int		val_len;

	temp = ft_strchr(cmd, '=');
	if (temp)
	{
		key_len = temp - cmd;
		val_len = ft_strlen(cmd) - key_len - 1;
		split_and_add_utils(cmd, shell, key_len, val_len);
	}
	else
	{
		key_len = ft_strlen(cmd);
		if (is_new_key(cmd, key_len, shell))
		{
			temp = get_key(cmd, key_len);
			env_add_back(&(shell->env), env_new(temp, NULL, 1));
		}
	}
	return ;
}

void	run_export_utils(t_cmd *command_list, t_shell *shell, t_arg_stt *arg)
{
	int	i;

	i = 1;
	while (command_list->argv[i])
	{
		if (arg->state)
		{
			split_and_add(command_list->argv[i], shell);
		}
		else
		{
			return ;
		}
		i++;
		arg = arg->next;
	}
}
