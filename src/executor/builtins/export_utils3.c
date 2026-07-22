/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 21:05:59 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 03:30:05 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_strlen_specified(char *str)
{
	if (!str)
		return (0);
	else
		return (ft_strlen(str));
}

void	change_the_value_of_key_1(t_shell *shell, char *cmd,
			int key_len, char *value)
{
	t_env	*traversal;
	int		new_val_len;
	char	*key;

	key = get_key(cmd, key_len);
	traversal = shell->env;
	new_val_len = ft_strlen(value);
	while (traversal)
	{
		if (ft_strncmp(traversal->key, key,
				get_bigger_string_len(traversal->key, key)) == 0)
		{
			free_them(&key, &(traversal->value), NULL, NULL);
			traversal->value = (char *)malloc(sizeof(char) * (new_val_len + 1));
			if (!traversal->value)
				fatal_error("malloc");
			(traversal->value)[new_val_len] = '\0';
			return (fill_it(value, traversal->value, new_val_len));
		}
		traversal = traversal->next;
	}
}

void	change_the_value_of_key(t_shell *shell, char *cmd, int key_len)
{
	change_the_value_of_key_1(shell, cmd, key_len, cmd + key_len + 1);
}
