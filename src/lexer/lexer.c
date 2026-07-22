/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:59:44 by fatmdemi          #+#    #+#             */
/*   Updated: 2026/07/18 18:03:27 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser_internal.h"
#include "lexer.h"

void	ms_free_tokens(t_token *tokens)
{
	t_token	*next;

	while (tokens)
	{
		next = tokens->next;
		free(tokens->text);
		free(tokens);
		tokens = next;
	}
}

static t_token	*lexer_fail(t_shell *shell, t_token *tokens)
{
	if (shell->last_status == 0)
		shell->last_status = 2;
	ms_free_tokens(tokens);
	return (NULL);
}

void	tokenize_line_initilaze(t_token **tokens,
		t_token **prev, t_lexer *lexer)
{
	*tokens = NULL;
	*prev = NULL;
	lexer->i = 0;
	if (lexer->i == 0 && *tokens == NULL && *prev == NULL)
		return ;
}

t_token	*tokenize_line(t_shell *shell, const char *line)
{
	t_token	*tokens;
	t_token	*token;
	t_token	*prev;
	t_lexer	lexer;

	tokenize_line_initilaze(&tokens, &prev, &lexer);
	while (line && line[lexer.i])
	{
		lexer_skip_spaces(line, &(lexer.i));
		if (!line[lexer.i])
			break ;
		if (lexer_is_metachar(line[lexer.i]))
			token = lexer_operator(line, &(lexer.i));
		else
			token = lex_word(shell, line, &lexer,
					prev && prev->type == TK_HEREDOC);
		if (!token && shell->last_status == 0)
			continue ;
		if (!token)
			return (lexer_fail(shell, tokens));
		token_add_back(&tokens, token);
		prev = token;
	}
	return (tokens);
}
