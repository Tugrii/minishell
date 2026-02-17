/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 21:23:05 by tgeler            #+#    #+#             */
/*   Updated: 2026/02/05 21:23:05 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H
# include "../../Libft/libft.h"
# include "executor_struct.h"

char	**obtain_path_list(char **envp);
char	**obtain_exact_paths(char **path_list, char **commands);
#endif