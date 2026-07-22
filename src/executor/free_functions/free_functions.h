/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 20:26:37 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 17:50:23 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_FUNCTIONS_H
# define FREE_FUNCTIONS_H
# include "../../../include/minishell.h"

typedef struct free_functions
{
	char	**splitted_path_list;
	char	*exact_path;
	char	**env_array;
}	t_temp;

void	free_all_then_exit(t_shell *shell, int exit_code);
void	print_external_error_then_exit(char *msg, t_temp *strs, t_shell *shell);
void	free_external_temps(t_temp *strs);
void	malloc_error(t_shell *shell, char *str1);
void	free_env_list(t_shell *shell, int mode, int exit_code);
void	close_all_fds(t_shell *shell, int mode);
#endif