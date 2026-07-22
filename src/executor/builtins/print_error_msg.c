/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_msg_export.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:07:58 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 03:34:56 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Libft/libft.h"
#include <stdio.h>

int	fatal_error(char *msg)
{
	perror(msg);
	exit(1);
}

int	print_error_msg_export(char *msg, int mode)
{
	int	len;

	if (msg)
		len = ft_strlen(msg);
	if (mode == 1)
	{
		if (len > 0)
			write(2, msg, len);
	}
	if (mode == 2)
	{
		write(2, "minishell: export: -", 20);
		write(2, msg, 1);
		write(2, ": invalid option\nexport: usage: export", 38);
		write(2, " [-fn] [name[=value] ...] or export -p\n", 39);
	}
	if (mode == 3)
	{
		write(2, "minishell: export:", 18);
		write(2, " `", 2);
		if (msg)
			write(2, msg, len);
		write(2, "': not a valid identifier\n", 26);
	}
	return (0);
}

int	print_error_msg_unset(char *msg, int mode)
{
	if (mode == 1)
	{
		write(2, "minishell: unset: -", 19);
		write(2, msg, 1);
		write(2, ": invalid option\nunset: usage: unset", 36);
		write(2, " [-f] [-v] [-n] [name ...]\n", 27);
	}
	return (1);
}

void	print_error_msg_exit(char *msg, int mode)
{
	int	len;

	if (mode == 1)
	{
		if (msg)
			len = ft_strlen(msg);
		write(2, "minishell: exit: ", 17);
		if (msg)
			write(2, msg, len);
		write(2, ": numeric argument required\n", 28);
	}
	if (mode == 2)
	{
		write(2, "minishell: exit: ", 17);
		write(2, "too many arguments\n", 19);
	}
}
