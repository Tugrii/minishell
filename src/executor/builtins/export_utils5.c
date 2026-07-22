/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:09:14 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 03:45:19 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

t_env	*clone_the_env(t_env *original, t_env *cloned_env)
{
	t_env	*traversal;
	char	*key;
	char	*value;

	traversal = original;
	while (traversal)
	{
		key = NULL;
		value = NULL;
		if (traversal->key)
		{
			key = ft_strdup(traversal->key);
			if (!key)
				fatal_error("malloc");
		}
		if (traversal->value)
		{
			value = ft_strdup(traversal->value);
			if (!value)
				fatal_error("malloc");
		}
		env_add_back(&cloned_env, env_new(key, value, traversal->exported));
		traversal = traversal->next;
	}
	return (cloned_env);
}

t_env	*swap_nodes_values(t_env *node_1, t_env *node_2)
{
	t_env	*temp;

	temp = malloc(sizeof(t_env));
	if (!temp)
		fatal_error("malloc");
	temp->key = node_1->key;
	temp->value = node_1->value;
	temp->exported = node_1->exported;
	node_1->key = node_2->key;
	node_1->value = node_2->value;
	node_1->exported = node_2->exported;
	node_2->key = temp->key;
	node_2->value = temp->value;
	node_2->exported = temp->exported;
	free (temp);
	return (node_2);
}

int	get_bigger_string_len(char *str1, char *str2)
{
	int		len_1;
	int		len_2;

	len_1 = ft_strlen_specified(str1);
	len_2 = ft_strlen_specified(str2);
	if (len_1 > len_2)
		return (len_1);
	else
		return (len_2);
}

void	sort_env_list(t_env **env)
{
	t_env	*traversal;
	t_env	*current;
	int		len;

	traversal = *env;
	while (traversal)
	{
		current = *env;
		while (current)
		{
			if (current->key && current->next)
				len = get_bigger_string_len(current->key, current->next->key);
			else
				break ;
			if (current->next && ft_strncmp(current->key,
					current->next->key, len) > 0)
				swap_nodes_values(current, current->next);
			current = current->next;
		}
		traversal = traversal->next;
	}
}
