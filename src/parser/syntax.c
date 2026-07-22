/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:59:44 by fatmdemi          #+#    #+#             */
/*   Updated: 2026/07/18 18:03:27 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

static int	redir_has_target(t_token *token)
{
	return (token->next && token->next->type == TK_WORD);
}

static int	syntax_pipe_error(t_token *token, t_token *prev)
{
	return (token->type == TK_PIPE && (!prev || prev->type == TK_PIPE));
}

int	check_syntax(t_token *tokens)
{
	t_token	*prev;

	prev = NULL;
	while (tokens)
	{
		if (syntax_pipe_error(tokens, prev))
			return (ms_syntax_error(parser_token_name(tokens)));
		if (parser_is_redir(tokens->type) && !redir_has_target(tokens))
			return (ms_syntax_error(parser_token_name(tokens->next)));
		prev = tokens;
		tokens = tokens->next;
	}
	if (prev && prev->type == TK_PIPE)
		return (ms_syntax_error("newline"));
	return (0);
}
