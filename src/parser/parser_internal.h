/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:59:44 by fatmdemi          #+#    #+#             */
/*   Updated: 2026/07/18 18:03:27 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_INTERNAL_H
# define PARSER_INTERNAL_H

# include "../../include/minishell.h"
# include "../lexer/lexer.h"

static inline void	ms_fatal(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

typedef struct s_argnode
{
	char				*text;
	struct s_argnode	*next;
}	t_argnode;

int			lexer_is_space(int c);
int			lexer_is_metachar(int c);
int			lexer_is_forbidden(int c);
void		lexer_skip_spaces(const char *line, int *i);
int			lexer_set_syntax_char(t_shell *shell, char c);
int			lexer_set_quote_error(t_shell *shell, char quote);
t_token		*token_new(t_toktype type, char *text, int quoted);
void		token_add_back(t_token **tokens, t_token *new_token);
t_token		*lexer_operator(const char *line, int *i);
t_token		*lex_word(t_shell *shell, const char *line, t_lexer *lexer,
						int is_heredoc_delim);
void		ms_free_tokens(t_token *tokens);
void		ms_free_redirs(t_redir *redirs);
void		ms_free_cmds(t_cmd *cmds);
int			ms_syntax_error(const char *token);
int			ms_unclosed_quote_error(char quote);
const char	*parser_token_name(t_token *token);
int			parser_is_redir(t_toktype type);
void		parser_cmd_add_back(t_cmd **head, t_cmd **tail, t_cmd *cmd);
void		arg_add_back(t_argnode **head, char *text);
char		**arg_list_to_array(t_argnode *head);
void		arg_list_free(t_argnode *head);
void		parser_redir_add_back(t_redir **head, t_redir *redir);
t_redir		*parser_build_redir(t_toktype type, t_token *target);
int			parser_parse_redir(t_token **tokens, t_redir **redirs);
t_cmd		*parse_command(t_token **tokens);
void		parser_redir_add_back(t_redir **head, t_redir *redir);
t_redir		*parser_build_redir(t_toktype type, t_token *target);
t_redirtype	redir_type_from_token(t_toktype type);

#endif
