/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_split_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:22:50 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/26 13:46:17 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map/table.h"
#include "utils/string.h"

static bool	match_option_key(const char *s, size_t len, const char *key)
{
	size_t	key_len;

	key_len = ft_strlen(key);
	if (len <= key_len)
		return (false);
	if (ft_strncmp(s, key, key_len) != 0)
		return (false);
	if (!table_is_space(s[key_len]))
		return (false);
	return (true);
}

static bool	line_is_option(const char *s, size_t len, t_opt_ctx *ctx)
{
	size_t	i;

	i = 0;
	while (i < len && table_is_space(s[i]))
		i++;
	if (i == len)
		return (false);
	s += i;
	len -= i;
	if (match_option_key(s, len, "NO"))
		return (ctx->no = true, true);
	if (match_option_key(s, len, "SO"))
		return (ctx->so = true, true);
	if (match_option_key(s, len, "WE"))
		return (ctx->we = true, true);
	if (match_option_key(s, len, "EA"))
		return (ctx->ea = true, true);
	if (match_option_key(s, len, "F"))
		return (ctx->f = true, true);
	if (match_option_key(s, len, "C"))
		return (ctx->c = true, true);
	return (false);
}

static bool	skip_empty_lines(const char *c, size_t *i)
{
	size_t	len;

	len = line_len(c + *i);
	if (!line_is_empty(c + *i, len))
		return (false);
	*i += len;
	if (c[*i] == '\n')
		(*i)++;
	return (true);
}

static bool	handle_option_lines(const char *c,
				size_t *i,
				t_opt_ctx *ctx)
{
	size_t	len;

	len = line_len(c + *i);
	if (!line_is_option(c + *i, len, ctx))
		return (false);
	*i += len;
	if (c[*i] == '\n')
		(*i)++;
	return (true);
}

bool	find_split_pos(const char *content, size_t *opt_end)
{
	t_opt_ctx	ctx;
	size_t		i;

	if (!content || !opt_end)
		return (false);
	ft_bzero(&ctx, sizeof(t_opt_ctx));
	i = 0;
	while (content[i])
	{
		if (skip_empty_lines(content, &i))
			continue ;
		if (!handle_option_lines(content, &i, &ctx))
			return (false);
		if (opt_ctx_complete(&ctx))
		{
			*opt_end = i;
			return (true);
		}
	}
	return (false);
}
