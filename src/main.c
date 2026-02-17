/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:18:33 by tgeler            #+#    #+#             */
/*   Updated: 2026/02/17 18:13:50 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"
#include "Libft/libft.h"

int main(int argc, char **argv, char **envp)
{
	exec_infos	minishell;

	minishell.envp = envp;
	// minishell.commands = zeynebin yaptigi parserden gelen commandı bulan fonksiyon
	minishell.cmd_count = calculate_command_count(minishell->commands);
	minishell.path_list = obtain_path_list(envp);
	minishell.exact_path_list = obtain_exact_paths(&minishell);
	execute(&minishell);
}
