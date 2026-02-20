/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:12:16 by fzeydem           #+#    #+#             */
/*   Updated: 2026/02/20 21:13:15 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_new(t_toktype type, char *value, int quoted)
{
	t_token	*tok;

	tok = (t_token *)malloc(sizeof(t_token));
	if (!tok)
	{
		free(value);
		return (NULL);
	}
	tok->type = type;
	tok->value = value;
	tok->quoted = quoted;
	tok->next = NULL;
	return (tok);
}

void	token_add_back(t_token **lst, t_token *new_tok)
{
	t_token	*cur;

	if (!lst || !new_tok)
		return ;
	if (!*lst)
	{
		*lst = new_tok;
		return ;
	}
	cur = *lst;
	while (cur->next)
		cur = cur->next;
	cur->next = new_tok;
}

void	free_tokens(t_token *toks)
{
	t_token	*next;

	while (toks)
	{
		next = toks->next;
		free(toks->value);
		free(toks);
		toks = next;
	}
}
