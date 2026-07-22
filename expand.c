/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:59:44 by fatmdemi          #+#    #+#             */
/*   Updated: 2026/07/18 18:03:27 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

static void	add_status(t_shell *shell, t_str *sb)
{
	char	*status;

	status = ms_itoa(shell->last_status);
	sb_adds(sb, status);
	free(status);
}

static void	add_name(t_shell *shell, t_str *sb, const char *text, int *i)
{
	int		start;
	char	*name;
	char	*value;

	start = *i;
	while (ms_isname_char(text[*i]))
		(*i)++;
	name = ms_substr(text, start, *i - start);
	value = env_get(shell->env, name);
	if (value)
		sb_adds(sb, value);
	free(name);
}

char	*expand_text(t_shell *shell, const char *text, int quoted, int i)
{
	t_str	sb;

	(void)quoted;
	sb_init(&sb);
	while (text[i])
	{
		if (text[i] != '$')
			sb_addc(&sb, text[i++]);
		else if (text[++i] == '?')
		{
			add_status(shell, &sb);
			i++;
		}
		else if (text[i] >= '0' && text[i] <= '9')
			i++;
		else if (ms_isname_start(text[i]))
			add_name(shell, &sb, text, &i);
		else
		{
			sb_addc(&sb, '$');
			if (text[i])
				sb_addc(&sb, text[i++]);
		}
	}
	return (sb_take(&sb));
}

char	*expand_heredoc_line(t_shell *shell, const char *line)
{
	return (expand_text(shell, line, 0, 0));
}
