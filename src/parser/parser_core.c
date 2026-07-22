/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:59:44 by fatmdemi          #+#    #+#             */
/*   Updated: 2026/07/18 18:03:27 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

const char	*parser_token_name(t_token *token)
{
	if (!token || !token->text || !*token->text)
		return ("newline");
	return (token->text);
}

int	parser_is_redir(t_toktype type)
{
	return (type == TK_IN || type == TK_OUT
		|| type == TK_HEREDOC || type == TK_APPEND);
}

void	parser_cmd_add_back(t_cmd **head, t_cmd **tail, t_cmd *cmd)
{
	if (!*head)
		*head = cmd;
	else
		(*tail)->next = cmd;
	*tail = cmd;
}
