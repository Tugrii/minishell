/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obtain_path_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 20:27:08 by tgeler            #+#    #+#             */
/*   Updated: 2026/02/03 20:27:08 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Libft/libft.h"

static char	*find_path_in_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			return (envp[i] + 5);
		i++;
	}
}

char	**obtain_path_list(char **envp)
{
	char	**path_list;
	char	*non_splitted_paths;

	non_splitted_path = find_path_in_envp(envp);
	path_list = ft_split(non_splitted_path, ':');
	return (path_list);
}
