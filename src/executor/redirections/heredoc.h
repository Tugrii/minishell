/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 15:55:57 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 17:29:41 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../free_functions/free_functions.h"
#include "../../../include/minishell.h"
#include "../builtins/builtins.h"
#include "../../signals/signals.h"

typedef struct heredoc
{
	char	*line;
	int		fd;
}	t_heredoc;

int		fd_error_heredoc(t_shell *shell, char *file_name);
void	write_to_file(char *line, int fd);
char	*create_unique_name(t_shell *shell, int redir_no, int command_no);
int		create_temp_file_then_write(t_shell *shell, t_redir *redir,
			int command_no, int redir_no);
int		pressed_ctrl_c(char *file_name, int fd);
void	pressed_ctrl_d(t_redir *redir);
void	matched_with_word(t_redir *redir, char *line);
int		set_target_close_fd(t_redir *redir, char *file_name, int fd);