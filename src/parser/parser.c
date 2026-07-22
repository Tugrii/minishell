/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:59:44 by fatmdemi          #+#    #+#             */
/*   Updated: 2026/07/18 18:03:27 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

void	ms_free_cmds(t_cmd *cmds)
{
	t_cmd	*next;

	while (cmds)
	{
		next = cmds->next;
		ms_free_matrix(cmds->argv);
		ms_free_redirs(cmds->redirs);
		free(cmds);
		cmds = next;
	}
}

static t_cmd	*parse_fail(t_cmd *cmds)
{
	ms_free_cmds(cmds);
	return (NULL);
}

t_cmd	*parse_tokens(t_token *tokens)
{
	t_cmd	*cmds;
	t_cmd	*tail;
	t_cmd	*cmd;

	cmds = NULL;
	tail = NULL;
	while (tokens)
	{
		cmd = parse_command(&tokens);
		if (!cmd)
			return (parse_fail(cmds));
		parser_cmd_add_back(&cmds, &tail, cmd);
		if (tokens && tokens->type == TK_PIPE)
			tokens = tokens->next;
	}
	return (cmds);
}
