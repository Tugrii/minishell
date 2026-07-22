/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 22:53:09 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 03:46:24 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	free_them(char **p_1, char **p_2, t_env **p_3, char **p_4)
{
	if (p_1 != NULL)
	{
		free(*p_1);
		*p_1 = NULL;
	}
	if (p_2 != NULL)
	{
		free(*p_2);
		*p_2 = NULL;
	}
	if (p_3 != NULL)
	{
		free(*p_3);
		*p_3 = NULL;
	}
	if (p_4 != NULL)
	{
		free(*p_4);
		*p_4 = NULL;
	}
}

char	*get_key(char *cmd, int key_len)
{
	char	*key;

	key = (char *)malloc(sizeof(char) * (key_len + 1));
	if (!key)
		fatal_error("malloc");
	key[key_len] = '\0';
	fill_it(cmd, key, key_len);
	return (key);
}

int	is_new_key(char *cmd, int key_len, t_shell *shell)
{
	t_env	*traversal;
	char	*key;

	traversal = shell->env;
	key = get_key(cmd, key_len);
	while (traversal)
	{
		if (ft_strncmp(traversal->key, key,
				get_bigger_string_len(traversal->key, key)) == 0)
		{
			free (key);
			return (0);
		}
		traversal = traversal->next;
	}
	free (key);
	return (1);
}

void	print_export(t_shell *shell)
{
	t_env	*traversal;
	t_env	*cloned_env;

	cloned_env = clone_the_env(shell->env, NULL);
	sort_env_list(&(cloned_env));
	traversal = cloned_env;
	while (traversal)
	{
		write(1, "declare -x ", 11);
		write(1, traversal->key, ft_strlen(traversal->key));
		if (traversal->value)
		{
			write(1, "=\"", 2);
			write(1, traversal->value, ft_strlen(traversal->value));
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
		traversal = traversal->next;
	}
	free_the_env(&cloned_env);
}
