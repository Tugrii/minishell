/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 00:20:56 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 00:07:18 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	run_pwd(t_shell *shell)
{
	char	*pwd;

	pwd = env_get(shell->env, "PWD");
	if (pwd)
	{
		write(1, pwd, ft_strlen(pwd));
		write(1, "\n", 1);
		shell->last_status = 0;
	}
	else
		shell->last_status = 1;
}
