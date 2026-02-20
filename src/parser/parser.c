/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:11:35 by fzeydem           #+#    #+#             */
/*   Updated: 2026/02/20 21:13:33 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cmd_add_back(t_cmd **lst, t_cmd *new_cmd)
{
	t_cmd	*cur;

	if (!lst || !new_cmd)
		return ;
	if (!*lst)
	{
		*lst = new_cmd;
		return ;
	}
	cur = *lst;
	while (cur->next)
		cur = cur->next;
	cur->next = new_cmd;
}

t_pipeline	*parse(t_token *toks, t_err *err)
{
	t_pipeline	*p;
	t_token		*cur;
	t_cmd		*cmd;

	if (!toks)
		return (NULL);
	p = (t_pipeline *)malloc(sizeof(t_pipeline));
	if (!p)
	{
		err_set(err, "minishell: malloc error");
		return (NULL);
	}
	p->cmds = NULL;
	cur = toks;
	while (cur)
	{
		if (cur->type == TOK_PIPE)
		{
			cur = cur->next;
			if (!cur)
				break ;
		}
		cmd = (t_cmd *)malloc(sizeof(t_cmd));
		if (!cmd)
		{
			err_set(err, "minishell: malloc error");
			return (NULL);
		}
		cmd->argv = NULL;
		cmd->redirs = NULL;
		cmd->next = NULL;
		cmd_add_back(&p->cmds, cmd);
		cur = cur->next;
	}
	return (p);
}
