/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:59:56 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/13 23:31:03 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	env_error(t_shell *shell)
{
	shell->last_status = 1;
	write(2, "minishell: env with arguments or options does not accept\n", 57);
}

void	run_env(t_shell *shell, t_cmd *command_list)
{
	t_env	*traversal;
	int		len;

	if (command_list->argc > 1)
		return (env_error(shell));
	traversal = shell->env;
	while (traversal)
	{
		if (traversal->value)
		{
			len = ft_strlen(traversal->key);
			write(1, traversal->key, len);
			if (traversal->value)
			{
				write(1, "=", 1);
				len = ft_strlen(traversal->value);
				write (1, traversal->value, len);
			}
			write(1, "\n", 1);
		}
		traversal = traversal->next;
	}
	shell->last_status = 0;
}
