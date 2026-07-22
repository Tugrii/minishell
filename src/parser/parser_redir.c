/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:59:44 by fatmdemi          #+#    #+#             */
/*   Updated: 2026/07/18 18:03:27 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

static t_token	*redir_target(t_token *token)
{
	t_token	*next;

	next = token->next;
	if (!next || next->type != TK_WORD)
		return (NULL);
	return (next);
}

t_redirtype	redir_type_from_token(t_toktype type)
{
	if (type == TK_IN)
		return (RD_IN);
	if (type == TK_OUT)
		return (RD_OUT);
	if (type == TK_APPEND)
		return (RD_APPEND);
	return (RD_HEREDOC);
}

void	ms_free_redirs(t_redir *redirs)
{
	t_redir	*next;

	while (redirs)
	{
		next = redirs->next;
		if (redirs->heredoc_fd >= 0)
			close(redirs->heredoc_fd);
		free(redirs->target);
		free(redirs);
		redirs = next;
	}
}

int	parser_parse_redir(t_token **tokens, t_redir **redirs)
{
	t_token	*target;

	target = redir_target(*tokens);
	if (!target)
		return (0);
	parser_redir_add_back(redirs, parser_build_redir((*tokens)->type, target));
	*tokens = target->next;
	return (1);
}
