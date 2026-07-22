/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:59:44 by fatmdemi          #+#    #+#             */
/*   Updated: 2026/07/18 18:03:27 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

void	arg_add_back(t_argnode **head, char *text)
{
	t_argnode	*node;
	t_argnode	*last;

	node = malloc(sizeof(t_argnode));
	if (!node)
		ms_fatal("malloc");
	node->text = text;
	node->next = NULL;
	if (!*head)
		*head = node;
	else
	{
		last = *head;
		while (last->next)
			last = last->next;
		last->next = node;
	}
}

static int	arg_count(t_argnode *head)
{
	int	count;

	count = 0;
	while (head && ++count)
		head = head->next;
	return (count);
}

char	**arg_list_to_array(t_argnode *head)
{
	char		**argv;
	int			i;
	t_argnode	*next;

	if (!head)
		return (NULL);
	argv = malloc(sizeof(char *) * (arg_count(head) + 1));
	if (!argv)
		ms_fatal("malloc");
	i = 0;
	while (head)
	{
		argv[i++] = head->text;
		next = head->next;
		free(head);
		head = next;
	}
	argv[i] = NULL;
	return (argv);
}

void	arg_list_free(t_argnode *head)
{
	t_argnode	*next;

	while (head)
	{
		next = head->next;
		free(head->text);
		free(head);
		head = next;
	}
}
