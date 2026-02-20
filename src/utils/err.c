/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 21:00:00 by fatmdemi          #+#    #+#             */
/*   Updated: 2026/02/20 21:13:42 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
void	err_clear(t_err *err)
{
	if (!err)
		return ;
	free(err->msg);
	err->msg = NULL;
	err->code = 0;
}

void	err_set(t_err *err, const char *msg)
{
	if (!err)
		return ;
	free(err->msg);
	err->msg = NULL;
	if (msg)
		err->msg = ft_strdup(msg);
	err->code = 1;
}

void	err_syntax(t_err *err, const char *tok)
{
	char	*msg;

	if (!err)
		return ;
	if (!tok)
		tok = "newline";
	msg = ft_strdup("minishell: syntax error near '");
	if (!msg)
	{
		err_set(err, "minishell: malloc error");
		return ;
	}
	if (tok[0])
		msg = ft_strdup_append(msg, tok);
	if (!msg)
	{
		err_set(err, "minishell: malloc error");
		return ;
	}
	err_set(err, msg);
	free(msg);
}
