/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:59:44 by fatmdemi          #+#    #+#             */
/*   Updated: 2026/07/18 18:03:27 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

char	*sb_take(t_str *sb)
{
	char	*taken;

	if (!sb->buf)
		return (ms_strdup(""));
	taken = sb->buf;
	sb->buf = NULL;
	sb->len = 0;
	sb->cap = 0;
	return (taken);
}

void	sb_free(t_str *sb)
{
	free(sb->buf);
	sb->buf = NULL;
	sb->len = 0;
	sb->cap = 0;
}

t_env	*env_new(char *key, char *value, int exported)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (!node)
		fatal_alloc("malloc");
	node->key = key;
	node->value = value;
	node->exported = exported;
	node->next = NULL;
	return (node);
}

void	env_add_back(t_env **env, t_env *node)
{
	t_env	*last;

	if (!*env)
		*env = node;
	else
	{
		last = *env;
		while (last->next)
			last = last->next;
		last->next = node;
	}
}
