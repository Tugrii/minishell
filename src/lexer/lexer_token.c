/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:59:44 by fatmdemi          #+#    #+#             */
/*   Updated: 2026/07/18 18:03:27 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser_internal.h"

t_token	*token_new(t_toktype type, char *text, int quoted)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		ms_fatal("malloc");
	token->type = type;
	token->text = text;
	token->quoted = quoted;
	token->next = NULL;
	return (token);
}

void	token_add_back(t_token **tokens, t_token *new_token)
{
	t_token	*last;

	if (!*tokens)
		*tokens = new_token;
	else
	{
		last = *tokens;
		while (last->next)
			last = last->next;
		last->next = new_token;
	}
}

static t_token	*operator_token(t_toktype type, const char *text)
{
	return (token_new(type, ms_strdup(text), 0));
}

t_token	*lexer_operator(const char *line, int *i)
{
	if (line[*i] == '|')
	{
		(*i)++;
		return (operator_token(TK_PIPE, "|"));
	}
	if (line[*i] == '<' && line[*i + 1] == '<')
	{
		(*i) += 2;
		return (operator_token(TK_HEREDOC, "<<"));
	}
	if (line[*i] == '>' && line[*i + 1] == '>')
	{
		(*i) += 2;
		return (operator_token(TK_APPEND, ">>"));
	}
	if (line[*i] == '<')
	{
		(*i)++;
		return (operator_token(TK_IN, "<"));
	}
	(*i)++;
	return (operator_token(TK_OUT, ">"));
}
