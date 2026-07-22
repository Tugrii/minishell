/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 17:57:48 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_process.h"
#include "../../free_functions/free_functions.h"

void	double_array_join(char **str, char *to_add_str)
{
	int		i;
	char	*temp;

	i = 0;
	while (str[i] != NULL)
	{
		temp = str[i];
		str[i] = ft_strjoin(str[i], to_add_str);
		if (!str[i])
			malloc_error(NULL, NULL);
		free(temp);
		i++;
	}
	return ;
}

char	*path_finder_utils(t_env *env)
{
	t_env	*traversal;
	int		len;

	traversal = env;
	while (traversal)
	{
		len = 0;
		if (traversal->key)
			len = ft_strlen(traversal->key);
		if (len < 5)
			len = 5;
		if ((ft_strncmp(traversal->key, "PATH", len) == 0))
			return (traversal->value);
		traversal = traversal->next;
	}
	return (NULL);
}

char	**path_finder(t_env *env)
{
	char	*non_splitted_path;
	char	**splitted_path;

	non_splitted_path = path_finder_utils(env);
	if (!non_splitted_path)
		return (NULL);
	splitted_path = ft_split(non_splitted_path, ':');
	if (!splitted_path)
		malloc_error(NULL, non_splitted_path);
	double_array_join(splitted_path, "/");
	return (splitted_path);
}
