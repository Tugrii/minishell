/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_then_exit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 18:28:09 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/06 17:38:04 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"
#include "../free_functions/free_functions.h"

int	print_error_then_exit(char *error_msg, t_shell *shell, int is_child)
{
	perror(error_msg);
	if (is_child)
		free_all_then_exit(shell, 1);
	else
		shell->last_status = 1;
	return (0);
}
