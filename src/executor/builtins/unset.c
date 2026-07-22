/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 00:26:52 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 03:33:18 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	unset_contain_flag(char *command, int len)
{
	char	*valid_flags_list;
	int		i;
	int		j;

	i = 1;
	valid_flags_list = "fvn";
	if (len > 0 && (ft_strncmp(command, "--help", len) == 0
			|| ft_strncmp(command, "--", len) == 0))
		return (0);
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
			return (print_error_msg_unset(&command[i], 1));
	}
	return (0);
}

t_env	*free_from_env_utils(t_env **head, t_env **env, t_env *temp)
{
	t_env	*traversal;
	t_env	*prev;

	if (*head == *env)
	{
		temp = *env;
		*head = (*env)->next;
		free_them(&(temp->key), &(temp->value), &temp, NULL);
	}
	else
	{
		traversal = *head;
		while (traversal)
		{
			if (traversal->next == *env)
			{
				prev = traversal;
				prev->next = (*env)->next;
				temp = *env;
				free_them(&(temp->key), &(temp->value), &temp, NULL);
			}
			traversal = traversal->next;
		}
	}
	return (*head);
}

void	free_from_env(t_cmd *command_list, t_shell *shell, int i)
{
	t_env	*traversal;

	while (command_list->argv[i])
	{
		traversal = shell->env;
		while (traversal)
		{
			if (!ft_strncmp(traversal->key, command_list->argv[i],
					get_bigger_string_len(traversal->key,
						command_list->argv[i])))
				traversal = free_from_env_utils(&(shell->env),
						&(traversal), NULL);
			else
				traversal = traversal->next;
		}
		i++;
	}
}

void	run_unset(t_cmd *command_list, t_shell *shell)
{
	int	i;
	int	err_occured;

	i = 1;
	err_occured = 0;
	if (command_list->argv[1] && command_list->argv[1][0] == '-')
	{
		if (unset_contain_flag(command_list->argv[1],
				ft_strlen_specified(command_list->argv[1])) == 1)
			err_occured = 2;
		i = 2;
	}
	free_from_env(command_list, shell, i);
	shell->last_status = err_occured;
}
