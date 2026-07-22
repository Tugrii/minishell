/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:59:44 by fatmdemi          #+#    #+#             */
/*   Updated: 2026/07/18 18:03:27 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser_internal.h"

int	ms_syntax_error(const char *token)
{
	write(2, "minishell: syntax error near unexpected token `", 47);
	if (token)
		write(2, token, ms_strlen(token));
	write(2, "'\n", 2);
	return (2);
}

int	ms_unclosed_quote_error(char quote)
{
	write(2, "minishell: unexpected EOF while looking for matching `", 54);
	write(2, &quote, 1);
	write(2, "'\n", 2);
	return (2);
}

int	lexer_is_space(int c)
{
	return (ms_isspace(c));
}

int	lexer_is_metachar(int c)
{
	return (c == '|' || c == '<' || c == '>');
}
