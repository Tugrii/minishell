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

static int	read_plain(t_shell *shell, t_word *word,
			const char *line, t_lexer *lexer)
{
	if (line[lexer->i] == '\\')
		return (read_escape(word, line, &(lexer->i)));
	if (line[lexer->i] == '$')
	{
		if (lexer->is_heredoc_delim)
		{
			word->keep_empty = 1;
			sb_addc(&word->str, line[lexer->i]);
			(lexer->i)++;
			return (1);
		}
		return (read_expand(shell, word, line, &(lexer->i)));
	}
	if (lexer_is_forbidden(line[lexer->i]))
		return (lexer_set_syntax_char(shell, line[lexer->i]));
	word->keep_empty = 1;
	sb_addc(&word->str, line[lexer->i]);
	(lexer->i)++;
	return (1);
}

void	initilaze_lex_word(int *keep_empty, int *quoted)
{
	*keep_empty = 0;
	*quoted = 0;
}

t_token	*lex_word(t_shell *shell, const char *line, t_lexer *lexer,
		int is_heredoc_delim)
{
	t_word	word;

	sb_init(&word.str);
	initilaze_lex_word(&(word.keep_empty), &(word.quoted));
	lexer->is_heredoc_delim = is_heredoc_delim;
	while (line[lexer->i] && !lexer_is_space(line[lexer->i])
		&& !lexer_is_metachar(line[lexer->i]))
	{
		if (line[lexer->i] == '\'')
		{
			if (!read_single(shell, &word, line, &(lexer->i)))
				return (sb_free(&word.str), NULL);
		}
		else if (line[lexer->i] == '"')
		{
			if (!read_double(shell, &word, line, lexer))
				return (sb_free(&word.str), NULL);
		}
		else if (!read_plain(shell, &word, line, lexer))
			return (sb_free(&word.str), NULL);
	}
	if (word.keep_empty || word.str.len > 0)
		return (token_new(TK_WORD, sb_take(&word.str), word.quoted));
	sb_free(&word.str);
	return (NULL);
}
