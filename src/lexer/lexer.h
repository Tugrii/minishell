/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:59:44 by fatmdemi          #+#    #+#             */
/*   Updated: 2026/07/18 18:03:27 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "../../include/minishell.h"

typedef struct s_lex
{
	int			i;
	int			is_heredoc_delim;
}	t_lexer;
int			ms_syntax_error(const char *token);
int			ms_unclosed_quote_error(char quote);
int			lexer_is_space(int c);
int			lexer_is_metachar(int c);
int			read_escape(t_word *word, const char *line, int *i);
int			read_expand(t_shell *shell, t_word *word, const char *line, int *i);
int			read_single(t_shell *shell, t_word *word, const char *line, int *i);
int			read_double(t_shell *shell, t_word *word,
				const char *line, t_lexer *lexer);
#endif