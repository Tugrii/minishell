/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 16:33:41 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/20 23:54:27 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <readline/readline.h>
#include "signals.h"

volatile sig_atomic_t	g_signal_status = 0;

void	handle_signals(int signum)
{
	if (signum == SIGINT)
	{
		g_signal_status = 130;
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	signal_initilaze(void)
{
	struct sigaction	sig;

	sigemptyset(&sig.sa_mask);
	sig.sa_flags = 0;
	sig.sa_handler = handle_signals;
	sigaction(SIGINT, &sig, NULL);
	sig.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sig, NULL);
}

void	handle_heredoc_signals(int signum)
{
	if (signum == SIGINT)
	{
		g_signal_status = 130;
		write(STDOUT_FILENO, "\n", 1);
		close(STDIN_FILENO);
	}
}

void	heredoc_signal_initilaze(void)
{
	struct sigaction	sig;

	sig.sa_handler = handle_heredoc_signals;
	sigemptyset(&(sig.sa_mask));
	sig.sa_flags = 0;
	sigaction(SIGINT, &sig, NULL);
	sig.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sig, NULL);
}
