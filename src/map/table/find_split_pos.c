/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_split_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:22:50 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/26 13:36:14 by lfiorell         ###   ########.fr       */
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

bool	find_split_pos(const char *content, size_t *opt_end)
{
	t_opt_ctx	ctx;
	size_t		i;
	bool		options_complete;
	bool		map_found;
	size_t		len;

	if (!content)
		return (false);
	ft_bzero(&ctx, sizeof(t_opt_ctx));
	options_complete = false;
	map_found = false;
	i = 0;
	while (content[i])
	{
		len = line_len(content + i);
		if (line_is_empty(content + i, len))
		{
			i += len;
			if (content[i] == '\n')
				i++;
			continue ;
		}
		if (!options_complete)
		{
			if (!line_is_option(content + i, len, &ctx))
				return (false);
			options_complete = opt_ctx_complete(&ctx);
			i += len;
			if (content[i] == '\n')
				i++;
			continue ;
		}
		if (!map_found)
		{
			*opt_end = i;
			map_found = true;
		}
		break ;
	}
	return (map_found);
}
