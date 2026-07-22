/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:59:44 by fatmdemi          #+#    #+#             */
/*   Updated: 2026/07/18 18:03:27 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

void	parser_redir_add_back(t_redir **head, t_redir *redir)
{
	t_redir	*last;

	if (!*head)
		*head = redir;
	else
	{
		last = *head;
		while (last->next)
			last = last->next;
		last->next = redir;
	}
}

t_redir	*parser_build_redir(t_toktype type, t_token *target)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	if (!redir)
		ms_fatal("malloc");
	redir->type = redir_type_from_token(type);
	redir->target = ms_strdup(target->text);
	if (!redir->target)
		ms_fatal("malloc");
	redir->quoted = target->quoted;
	redir->heredoc_fd = -1;
	redir->next = NULL;
	return (redir);
}
