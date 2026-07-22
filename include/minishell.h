/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:09:41 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/20 22:52:48 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>
# include "../src/signals/signals.h"

# define MS_PROMPT "minishell$ "

typedef enum e_toktype
{
	TK_WORD,
	TK_PIPE,
	TK_IN,
	TK_OUT,
	TK_HEREDOC,
	TK_APPEND
}	t_toktype;

typedef enum e_redirtype
{
	RD_IN,
	RD_OUT,
	RD_APPEND,
	RD_HEREDOC
}	t_redirtype;

typedef struct s_str
{
	char	*buf;
	size_t	len;
	size_t	cap;
}	t_str;

typedef struct s_word
{
	t_str	str;
	int		keep_empty;
	int		quoted;
}	t_word;

typedef struct s_token
{
	t_toktype		type;
	char			*text;
	int				quoted;
	struct s_token	*next;
}	t_token;

typedef struct s_redir
{
	t_redirtype		type;
	char			*target;
	int				quoted;
	int				heredoc_fd;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	char			**argv;
	int				argc;
	t_redir			*redirs;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_env
{
	char			*key;
	char			*value;
	int				exported;
	struct s_env	*next;
}	t_env;

typedef struct s_shell
{
	t_env	*env;
	int		last_status;
	int		next_fds[2];
	int		old_fd;
	t_cmd	*cmd;
	t_token	*token;
	int		orig_stdin;
	int		orig_stdout;
	int		has_pipe_in_line;
}	t_shell;

void		free_token(t_token *token);
void		free_cmd(t_cmd *cmd);
size_t		ms_strlen(const char *s);
char		*ms_strdup(const char *s);
int			ms_strcmp(const char *s1, const char *s2);
int			ms_isspace(int c);
int			ms_isalpha(int c);
int			ms_isalnum(int c);
int			ms_isname_start(int c);
int			ms_isname_char(int c);
char		*ms_strndup(const char *s, size_t n);
char		*ms_substr(const char *s, size_t start, size_t len);
int			ms_arrlen(char **arr);
void		ms_free_matrix(char **arr);
char		*ms_itoa(int n);
void		sb_init(t_str *sb);
void		sb_reserve(t_str *sb, size_t need);
void		sb_addc(t_str *sb, char c);
void		sb_adds(t_str *sb, const char *s);
char		*sb_take(t_str *sb);
void		sb_free(t_str *sb);
t_env		*env_new(char *key, char *value, int exported);
void		env_add_back(t_env **env, t_env *node);
t_env		*env_find(t_env *env, const char *key);
char		*env_get(t_env *env, const char *key);
int			env_key_len(const char *entry);
int			env_valid_key(const char *key);
t_env		*env_from_array(char **envp);
int			env_set(t_env **env, const char *key, const char *value, int exp);
t_token		*tokenize_line(t_shell *shell, const char *line);
int			check_syntax(t_token *tokens);
t_cmd		*parse_tokens(t_token *tokens);
char		*expand_text(t_shell *shell, const char *text, int quoted, int i);
char		*expand_heredoc_line(t_shell *shell, const char *line);
void		fatal_alloc(const char *message);
void		loop_ended(t_shell *shell);
void		set_signal_if_pressed_ctrl_c(t_shell *shell);
void		disable_echoctl(void);

#endif
