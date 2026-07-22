/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions_external.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:39:38 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 17:48:13 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_functions.h"
#include "../../../Libft/libft.h"

void	free_double_array(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free (argv[i]);
		i++;
	}
	free (argv);
}

void	free_external_temps(t_temp *strs)
{
	free(strs->exact_path);
	free_double_array(strs->splitted_path_list);
	free_double_array(strs->env_array);
}

void	print_external_error_then_exit(char *msg, t_temp *strs, t_shell *shell)
{
	free_external_temps(strs);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	if (errno == ENOENT)
		free_all_then_exit(shell, 127);
	else if (errno == EACCES)
		free_all_then_exit(shell, 126);
	else
		free_all_then_exit(shell, 1);
}
