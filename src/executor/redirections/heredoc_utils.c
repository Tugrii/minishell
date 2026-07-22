/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 15:54:02 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 17:28:24 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

int	fd_error_heredoc(t_shell *shell, char *file_name)
{
	perror("minishell : heredoc fd");
	free(file_name);
	shell->last_status = 1;
	return (0);
}

void	write_to_file(char *line, int fd)
{
	int	len;

	len = ft_strlen(line);
	write(fd, line, len);
	write(fd, "\n", 1);
	free (line);
}

char	*create_unique_name(t_shell *shell, int redir_no, int command_no)
{
	char	*temp;
	char	*file_name;
	char	*r_no;
	char	*c_no;

	file_name = NULL;
	r_no = ft_itoa(redir_no);
	if (!r_no)
		malloc_error(shell, NULL);
	c_no = ft_itoa(command_no);
	if (!c_no)
		malloc_error(shell, r_no);
	temp = ft_strjoin("penguen_", r_no);
	free(r_no);
	if (!temp)
		malloc_error(shell, NULL);
	file_name = ft_strjoin(temp, c_no);
	free(c_no);
	free(temp);
	if (!file_name)
		malloc_error(shell, NULL);
	return (file_name);
}
