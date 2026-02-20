/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:19:56 by tgeler            #+#    #+#             */
/*   Updated: 2026/02/20 21:01:08 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "src/executor/executor.h"

typedef enum e_toktype
{
	TOK_WORD,
	TOK_PIPE,
	TOK_REDIR_IN,
	TOK_REDIR_OUT,
	TOK_HEREDOC,
	TOK_APPEND
} 	t_toktype;

typedef struct s_token
{
	t_toktype			type;
	char				*value;
	int					quoted;
	struct s_token		*next;
} 	t_token;

typedef enum e_redir_type
{
	R_IN,
	R_OUT,
	R_HEREDOC,
	R_APPEND
} 	t_redir_type;

typedef struct s_redir
{
	t_redir_type		type;
	char				*target;
	int					heredoc_quoted;
	struct s_redir		*next;
} 	t_redir;

typedef struct s_cmd
{
	char				**argv;
	t_redir				*redirs;
	struct s_cmd		*next;
} 	t_cmd;

typedef struct s_pipeline
{
	t_cmd				*cmds;
} 	t_pipeline;

typedef struct s_strlist
{
	char				*s;
	struct s_strlist	*next;
} 	t_strlist;

typedef struct s_err
{
	int					code;
	char				*msg;
	int					last_status;
} 	t_err;

/* parser api */
t_token		*lex(const char *line, t_err *err);
t_pipeline	*parse(t_token *toks, t_err *err);

/* token utils */
t_token		*token_new(t_toktype type, char *value, int quoted);
void		token_add_back(t_token **lst, t_token *new_tok);
void		free_tokens(t_token *toks);

/* error utils */
void		err_clear(t_err *err);
void		err_set(t_err *err, const char *msg);
void		err_syntax(t_err *err, const char *tok);

#endif
