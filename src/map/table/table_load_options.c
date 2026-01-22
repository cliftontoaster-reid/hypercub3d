/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_load_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:05:49 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/22 12:20:02 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/colour.h"
#include "graphics/image.h"
#include "libft.h"
#include "map/table.h"
#include "utils/error.h"

bool	opt_ctx_complete(t_opt_ctx *c)
{
	return (c->no && c->so && c->we && c->ea && c->f && c->c);
}

static bool	is_str_empty_or_whitespace(const char *s)
{
	while (*s)
	{
		if (!table_is_space(*s))
			return (false);
		s++;
	}
	return (true);
}

static void	free_split(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
		free(lines[i++]);
	free(lines);
}

static bool	parse_option_lines(t_table *t, char **lines, t_opt_ctx *ctx)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (is_str_empty_or_whitespace(lines[i]))
		{
			i++;
			continue ;
		}
		if (!table_parse_option_line(t, lines[i], ctx))
		{
			free_split(lines);
			return (false);
		}
		i++;
	}
	free_split(lines);
	return (true);
}

bool	table_load_options(t_table *t, const char *options)
{
	t_opt_ctx	ctx;
	char		**lines;

	if (!t || !options)
		return (false);
	ft_bzero(&ctx, sizeof(t_opt_ctx));
	lines = ft_split(options, '\n');
	if (!lines)
		return (false);
	if (!parse_option_lines(t, lines, &ctx))
		return (false);
	if (!opt_ctx_complete(&ctx))
	{
		err_msg("Options", "Missing required options (NO, SO, WE, EA, F, C)");
		return (false);
	}
	return (true);
}
