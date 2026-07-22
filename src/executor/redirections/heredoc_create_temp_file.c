/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_create_temp_file.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 16:31:06 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/20 01:29:16 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

static char	*maybe_expand_heredoc_line(t_shell *shell, t_redir *redir,
	char *line)
{
	char	*expanded;

	if (redir->quoted)
		return (line);
	expanded = expand_heredoc_line(shell, line);
	free(line);
	return (expanded);
}

int	get_file_name_open_fd(t_shell *shell, char **file_name,
	int redir_no, int command_no)
{
	int		fd;
	char	*current_dir;
	char	*unique_name;

	unique_name = create_unique_name(shell, redir_no, command_no);
	current_dir = getcwd(NULL, 0);
	if (!current_dir)
	{
		*file_name = ft_strjoin("/tmp/", unique_name);
		free (unique_name);
		if (!(*file_name))
			malloc_error(shell, NULL);
	}
	else
	{
		*file_name = ft_strjoin(current_dir, unique_name);
		free (unique_name);
		free (current_dir);
		if (!(*file_name))
			malloc_error(shell, NULL);
	}
	fd = open(*file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		return (fd_error_heredoc(shell, *file_name));
	return (fd);
}

int	ft_strncmp_specified(char *str1, char *str2)
{
	int	len;

	len = get_bigger_string_len(str1, str2);
	return (ft_strncmp(str1, str2, len));
}

int	create_temp_file_then_write(t_shell *shell,
	t_redir *redir, int command_no, int redir_no)
{
	char		*file_name;
	t_heredoc	hrd;

	hrd.fd = get_file_name_open_fd(shell, &file_name, redir_no, command_no);
	if (hrd.fd == -1)
		return (0);
	while (1)
	{
		hrd.line = readline("> ");
		if (!(hrd.line))
		{
			if (isatty(0) == 0)
				return (pressed_ctrl_c(file_name, hrd.fd));
			pressed_ctrl_d(redir);
			break ;
		}
		if (ft_strncmp_specified(hrd.line, redir->target) == 0)
		{
			matched_with_word(redir, hrd.line);
			break ;
		}
		hrd.line = maybe_expand_heredoc_line(shell, redir, hrd.line);
		write_to_file(hrd.line, hrd.fd);
	}
	return (set_target_close_fd(redir, file_name, hrd.fd));
}
