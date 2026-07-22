/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:59:44 by fatmdemi          #+#    #+#             */
/*   Updated: 2026/07/18 18:03:27 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser_internal.h"
#include "lexer.h"

int	lexer_is_forbidden(int c)
{
	return (c == ';' || c == '&' || c == '(' || c == ')');
}

void	lexer_skip_spaces(const char *line, int *i)
{
	while (line[*i] && lexer_is_space(line[*i]))
		(*i)++;
}

int	lexer_set_syntax_char(t_shell *shell, char c)
{
	char	token[2];

	token[0] = c;
	token[1] = '\0';
	shell->last_status = ms_syntax_error(token);
	return (0);
}

int	lexer_set_quote_error(t_shell *shell, char quote)
{
	shell->last_status = ms_unclosed_quote_error(quote);
	return (0);
}
