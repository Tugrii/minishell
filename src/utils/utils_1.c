/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:59:44 by fatmdemi          #+#    #+#             */
/*   Updated: 2026/07/18 18:03:27 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

int	env_valid_key(const char *key)
{
	int	index;

	if (!key || !ms_isname_start((unsigned char)key[0]))
		return (0);
	index = 1;
	while (key[index])
	{
		if (!ms_isname_char((unsigned char)key[index]))
			return (0);
		index++;
	}
	return (1);
}

t_env	*env_from_array(char **envp)
{
	t_env	*env;
	int		index;
	int		sep;
	char	*key;
	char	*value;

	env = NULL;
	index = 0;
	while (envp && envp[index])
	{
		sep = env_key_len(envp[index]);
		key = ms_strndup(envp[index], sep);
		if (!key)
			fatal_alloc("malloc");
		if (envp[index][sep] == '=')
			value = ms_strdup(envp[index] + sep + 1);
		else
			value = ms_strdup("");
		if (!value)
			fatal_alloc("malloc");
		env_add_back(&env, env_new(key, value, 1));
		index++;
	}
	return (env);
}

int	env_set(t_env **env, const char *key, const char *value, int exp)
{
	t_env	*node;
	char	*dup_value;

	if (!env_valid_key(key))
		return (1);
	if (value)
		dup_value = ms_strdup(value);
	else
		dup_value = ms_strdup("");
	node = env_find(*env, key);
	if (!node)
	{
		node = env_new(ms_strdup(key), dup_value, exp);
		env_add_back(env, node);
		return (0);
	}
	free(node->value);
	node->value = dup_value;
	node->exported = exp;
	return (0);
}
