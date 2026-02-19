#include "minishell.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

static int	is_metachar(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

static t_token	*lex_operator(const char *line, size_t *i)
{
	if (line[*i] == '|')
	{
		(*i)++;
		return (token_new(TOK_PIPE, ft_strdup("|"), 0));
	}
	if (line[*i] == '<')
	{
		(*i)++;
		return (token_new(TOK_REDIR_IN, ft_strdup("<"), 0));
	}
	if (line[*i] == '>')
	{
		(*i)++;
		return (token_new(TOK_REDIR_OUT, ft_strdup(">"), 0));
	}
	return (NULL);
}

t_token	*lex(const char *line, t_err *err)
{
	size_t		i;
	t_token		*toks;
	t_token		*tok;
	char		*word;

	if (!line)
		return (NULL);
	i = 0;
	toks = NULL;
	while (line[i])
	{
		while (line[i] && is_space(line[i]))
			i++;
		if (!line[i])
			break ;
		if (is_metachar(line[i]))
		{
			tok = lex_operator(line, &i);
		}
		else
		{
			word = ft_strdup("");
			while (line[i] && !is_space(line[i]) && !is_metachar(line[i]))
			{
				char	c[2];
				c[0] = line[i];
				c[1] = '\0';
				word = ft_strdup_append(word, c);
				i++;
			}
			tok = token_new(TOK_WORD, word, 0);
		}
		if (!tok)
		{
			free_tokens(toks);
			err_set(err, "minishell: malloc error");
			return (NULL);
		}
		token_add_back(&toks, tok);
	}
	return (toks);
}
