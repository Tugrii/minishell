/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obtain_splitted_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:11:28 by tgeler            #+#    #+#             */
/*   Updated: 2026/02/02 19:11:28 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Libft/libft.h"

char	*find_path_in_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			return(envp[i]);
		i++;
	}
}

int		calculate_path_count(char *non_splitted_path)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (non_splitted_path[i] != '\0')
	{
		if (non_splitted_path[i] == ':')
			count++;
		i++;
	}
	return (count + 1);
}

char	obtain_splitted_path_utils2(char *non_splitted_path, char **path_list)
{
	while (non_splitted_path[i] != '\0')
	{
		if (non_splitted_path[i] != ':')
		{
			size++;
			
		}
		else
		{
			size = 0;
			path_list[j];
			j++;
		}
		i++;
	}
	return (*path_list)
}

char	obtain_splitted_path_utils1(char *non_splitted_path, char **path_list)
{
	int		i;
	int		size;
	int		j;
	int		path_count;

	i = 0;
	size = 0;
	path_count = calculate_path_count(non_splitted_path);
	path_list = (char *)malloc((path_count + 1)* sizeof(char *));
	if (!(*path_list))
		return (NULL);
	path_list[path_count] = NULL;
	return (obtain_splitted_path_utils2(non_splitted_path, path_list));
}

char	**obtain_splitted_path(char **envp)
{
	char	**path_list;
	char	*non_splitted_path;

	non_splitted_path = find_path_in_envp(envp);
	obtain_splitted_path_utils(non_splitted_path, &path_list);
	return (path_list);
}
