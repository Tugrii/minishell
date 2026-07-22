/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:59:44 by fatmdemi          #+#    #+#             */
/*   Updated: 2026/07/18 18:03:27 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

static void	free_partial(t_argnode *args, t_redir *redirs)
{
	arg_list_free(args);
	ms_free_redirs(redirs);
}

static void	parse_word_token(t_argnode **args, t_token *token)
{
	arg_add_back(args, ms_strdup(token->text));
}

static int	parse_part(t_token **tokens, t_argnode **args, t_redir **redirs)
{
	if ((*tokens)->type == TK_WORD)
	{
		parse_word_token(args, *tokens);
		*tokens = (*tokens)->next;
		return (1);
	}
	return (parser_parse_redir(tokens, redirs));
}

static t_cmd	*cmd_new(t_argnode *args, t_redir *redirs)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		ms_fatal("malloc");
	cmd->argv = arg_list_to_array(args);
	cmd->argc = ms_arrlen(cmd->argv);
	cmd->redirs = redirs;
	cmd->next = NULL;
	return (cmd);
}

t_cmd	*parse_command(t_token **tokens)
{
	t_argnode	*args;
	t_redir		*redirs;

	args = NULL;
	redirs = NULL;
	while (*tokens && (*tokens)->type != TK_PIPE)
	{
		if (!parse_part(tokens, &args, &redirs))
			return (free_partial(args, redirs), NULL);
	}
	return (cmd_new(args, redirs));
}
