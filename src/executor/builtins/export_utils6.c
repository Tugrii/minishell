/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 22:36:08 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/03 02:05:14 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	free_the_env(t_env **env)
{
	t_env	*temp;

	while (*env)
	{
		temp = *env;
		free (temp->key);
		free (temp->value);
		*env = temp->next;
		free (temp);
	}
}

void	free_state_list(t_arg_stt **list)
{
	t_arg_stt	*temp;

	while (*list)
	{
		temp = (*list)->next;
		free(*list);
		*list = temp;
	}
}
