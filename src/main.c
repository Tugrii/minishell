/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:18:33 by tgeler            #+#    #+#             */
/*   Updated: 2026/02/09 16:25:22 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"
#include "Libft/libft.h"

int main(int argc, char **argv, char **envp)
{
	path_info	minishell;

	minishell.env = envp;
	minishell.path_list = obtain_path_list(envp);
	minishell.exact_path_list = obtain_exact_paths(minishell.path_list, HER BIRININ ILK ARGUMANINI ICEREN STRING LISTESI);
	execute(&minishell);
}
