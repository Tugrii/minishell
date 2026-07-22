/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_creater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 17:55:31 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_process.h"
#include "../../free_functions/free_functions.h"

static char	*check_path_validity(char *path,
			char *cmd, char mode)
{
	char	*temp;

	temp = NULL;
	if (mode == '0')
	{
		temp = ft_strdup(cmd);
		if (!temp)
			malloc_error(NULL, NULL);
		if (access(cmd, 1) == 0)
			return (temp);
	}
	else if (mode == '1')
	{
		if (access(path, 1) == 0)
			return (path);
	}
	free (temp);
	return (NULL);
}

static char	*path_joiner(char *path, char *cmd)
{
	char	*new_path;

	new_path = ft_strjoin(path, cmd);
	if (!new_path)
		malloc_error(NULL, NULL);
	return (new_path);
}

char	*path_creater(char **paths, char *cmd)
{
	int		i;
	char	*temp_path;

	i = 0;
	temp_path = NULL;
	if (cmd)
	{
		if (ft_strchr(cmd, '/'))
			return (check_path_validity(temp_path, cmd, '0'));
		else if (paths)
		{
			while (paths[i] != NULL)
			{
				temp_path = path_joiner(paths[i], cmd);
				if (check_path_validity(temp_path, cmd, '1') != NULL)
					return (temp_path);
				else
					free (temp_path);
				i++;
			}
		}
	}
	return (NULL);
}
