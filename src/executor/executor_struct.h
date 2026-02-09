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

typedef struct minishell
{
	char	**path_list;
	char	**exact_path_list;
	char	**commands;
}path_info;

#endif
