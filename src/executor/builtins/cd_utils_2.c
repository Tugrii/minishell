/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 02:12:14 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/19 04:03:41 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../free_functions/free_functions.h"

void	oldpwd_error(t_shell *shell, char *old_pwd)
{
	write(2, "minishell: cd: OLDPWD not set\n", 30);
	shell->last_status = 1;
	free(old_pwd);
}
