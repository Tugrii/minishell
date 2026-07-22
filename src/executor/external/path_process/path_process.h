/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_process.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 16:06:00 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/04 18:56:32 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_PROCESS_H
# define PATH_PROCESS_H
# include "../../../../Libft/libft.h"
# include "../../../../include/minishell.h"

char	**path_finder(t_env *env);
char	*path_creater(char **paths, char *cmd);
#endif
