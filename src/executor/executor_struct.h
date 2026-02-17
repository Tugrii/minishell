/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 21:37:29 by tgeler            #+#    #+#             */
/*   Updated: 2026/02/05 21:37:29 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_STRUCT_H
# define EXECUTOR_STRUCT_H

# include "<sys/wait.h>"
typedef struct minishell
{
	char	**path_list;
	char	**exact_path_list;
	char	***commands;
	char	**envp;
	pid_t	*child_pids;
	int		fds[2];
}path_info;

int	calculate_command_count(char ***commands);

#endif
