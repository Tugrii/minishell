/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:09:53 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 03:08:29 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

t_arg_stt	*create_new_node(void)
{
	t_arg_stt	*new_node;

	new_node = malloc(sizeof(t_arg_stt));
	if (!new_node)
		return (NULL);
	new_node->state = 1;
	new_node->next = NULL;
	return (new_node);
}

void	add_back(t_arg_stt **argv, t_arg_stt *new_node)
{
	t_arg_stt	*tmp;

	if (!argv || !new_node)
		return ;
	if (*argv == NULL)
	{
		*argv = new_node;
		return ;
	}
	tmp = *argv;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	return ;
}

void	create_state_list_and_fill(t_arg_stt **state, t_cmd *command_list)
{
	int			i;
	int			arg_count;

	i = 0;
	while (command_list->argv[i])
		i++;
	if (i == 1)
		return ;
	arg_count = i - 1;
	i = 0;
	while (i < arg_count)
	{
		add_back(state, create_new_node());
		i++;
	}
	return ;
}

int	sign_and_print_err(t_export *export, char *msg, int err_no, int arg_no)
{
	int			i;
	t_arg_stt	*traversal;

	traversal = export->state_list;
	i = 1;
	while (i < arg_no)
	{
		traversal = traversal->next;
		i++;
	}
	traversal->state = 0;
	print_error_msg_export(msg, err_no);
	export->shell->last_status = 1;
	if (err_no == 2)
		return (2);
	return (1);
}
