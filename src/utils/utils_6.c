/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:59:44 by fatmdemi          #+#    #+#             */
/*   Updated: 2026/07/18 18:03:27 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

void	sb_init(t_str *sb)
{
	sb->buf = NULL;
	sb->len = 0;
	sb->cap = 0;
}

void	sb_reserve(t_str *sb, size_t need)
{
	char	*new_buf;
	size_t	new_cap;

	if (need + 1 <= sb->cap)
		return ;
	new_cap = sb->cap;
	if (new_cap == 0)
		new_cap = 16;
	while (new_cap < need + 1)
		new_cap *= 2;
	new_buf = realloc(sb->buf, new_cap);
	if (!new_buf)
		fatal_alloc("realloc");
	sb->buf = new_buf;
	sb->cap = new_cap;
}

void	sb_addc(t_str *sb, char c)
{
	sb_reserve(sb, sb->len + 1);
	sb->buf[sb->len++] = c;
	sb->buf[sb->len] = '\0';
}

void	sb_adds(t_str *sb, const char *s)
{
	size_t	index;

	if (!s)
		return ;
	index = 0;
	while (s[index])
		sb_addc(sb, s[index++]);
}
