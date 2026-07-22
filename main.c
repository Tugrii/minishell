/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:18:33 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/21 04:27:15 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"
#include "src/executor/executor.h"
#include "src/executor/free_functions/free_functions.h"

void	main_initilaze(t_shell *shell, int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	shell->env = env_from_array(envp);
	shell->last_status = 0;
	shell->old_fd = -1;
	signal_initilaze();
	shell->orig_stdin = dup(0);
	shell->orig_stdout = dup(1);
	shell->next_fds[0] = -1;
	shell->next_fds[1] = -1;
}

void	execute_then_free(t_shell *shell, t_cmd *cmds, t_token *tokens)
{
	execute_it(cmds, shell);
	free_token(tokens);
	free_cmd(cmds);
	close_all_fds(shell, 1);
}

static t_cmd	*validate_and_parse(t_shell *shell, t_token *tokens)
{
	if (check_syntax(tokens) != 0)
	{
		free_token(tokens);
		shell->last_status = 2;
		return (NULL);
	}
	return (parse_tokens(tokens));
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*line;

	main_initilaze(&shell, argc, argv, envp);
	while (1)
	{
		signal_initilaze();
		shell.has_pipe_in_line = 0;
		line = readline(MS_PROMPT);
		set_signal_if_pressed_ctrl_c(&shell);
		if (!line)
			break ;
		if (*line)
			add_history(line);
		shell.token = tokenize_line(&shell, line);
		free(line);
		if (!shell.token)
			continue ;
		shell.cmd = validate_and_parse(&shell, shell.token);
		if (!shell.cmd)
			continue ;
		execute_then_free(&shell, shell.cmd, shell.token);
	}
	loop_ended(&shell);
	return (shell.last_status);
}
