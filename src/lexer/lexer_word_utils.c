/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:59:44 by fatmdemi          #+#    #+#             */
/*   Updated: 2026/07/18 18:03:27 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser_internal.h"
#include "lexer.h"

int	read_escape(t_word *word, const char *line, int *i)
{
	if (!line[*i + 1])
	{
		sb_addc(&word->str, line[*i]);
		(*i)++;
		return (1);
	}
	sb_addc(&word->str, line[*i + 1]);
	(*i) += 2;
	return (1);
}

int	read_expand(t_shell *shell, t_word *word, const char *line, int *i)
{
	char	*name;
	char	*text;
	int		start;

	(*i)++;
	if (line[*i] == '?')
		return (text = ms_itoa(shell->last_status),
			sb_adds(&word->str, text), free(text), (*i)++, 1);
	if (line[*i] >= '0' && line[*i] <= '9')
		return ((*i)++, 1);
	if (!ms_isname_start(line[*i]))
		return (sb_addc(&word->str, '$'), 1);
	start = *i;
	while (ms_isname_char(line[*i]))
		(*i)++;
	name = ms_substr(line, start, *i - start);
	text = env_get(shell->env, name);
	if (text)
		sb_adds(&word->str, text);
	free(name);
	return (1);
}

int	read_single(t_shell *shell, t_word *word, const char *line, int *i)
{
	word->keep_empty = 1;
	word->quoted = 1;
	(*i)++;
	while (line[*i] && line[*i] != '\'')
		sb_addc(&word->str, line[(*i)++]);
	if (!line[*i])
		return (lexer_set_quote_error(shell, '\''));
	(*i)++;
	return (1);
}

int	read_double(t_shell *shell, t_word *word,
			const char *line, t_lexer *lexer)
{
	word->keep_empty = 1;
	word->quoted = 1;
	(lexer->i)++;
	while (line[lexer->i] && line[lexer->i] != '"')
	{
		if (line[lexer->i] == '\\')
			read_escape(word, line, &(lexer->i));
		else if (line[lexer->i] == '$')
		{
			if (lexer->is_heredoc_delim)
				sb_addc(&word->str, line[(lexer->i)++]);
			else if (!read_expand(shell, word, line, &(lexer->i)))
				return (0);
		}
		else
			sb_addc(&word->str, line[(lexer->i)++]);
	}
	if (!line[lexer->i])
		return (lexer_set_quote_error(shell, '"'));
	(lexer->i)++;
	return (1);
}
