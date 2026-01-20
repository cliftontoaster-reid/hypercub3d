/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_load_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:05:49 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/20 12:35:02 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/colour.h"
#include "graphics/image.h"
#include "libft.h"
#include "map/table.h"

#define CMP ft_strncmp

static void	free_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
		free(lines[i++]);
	free(lines);
}

static bool	parse_option_line(t_table *t, char *l, t_opt_ctx *c)
{
	if (CMP(l, "NO ", 3) == 0)
		return (ld(&t->no_wall, l + 3, t, &c->no));
	if (CMP(l, "SO ", 3) == 0)
		return (ld(&t->so_wall, l + 3, t, &c->so));
	if (CMP(l, "WE ", 3) == 0)
		return (ld(&t->we_wall, l + 3, t, &c->we));
	if (CMP(l, "EA ", 3) == 0)
		return (ld(&t->ea_wall, l + 3, t, &c->ea));
	if (CMP(l, "F ", 2) == 0)
		return (lrgb(&t->floor_col, l + 2, t, &c->f));
	if (CMP(l, "C ", 2) == 0)
		return (lrgb(&t->ceil_col, l + 2, t, &c->c));
	return (false);
}

static bool	parse_option_lines(t_table *t, char **lines, t_opt_ctx *ctx)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (!parse_option_line(t, lines[i], ctx))
		{
			free_lines(lines);
			return (false);
		}
		i++;
	}
	free_lines(lines);
	return (true);
}

bool	table_load_options(t_table *t, const char *options)
{
	t_opt_ctx	ctx;
	char		**lines;

	if (!t || !options)
		return (false);
	opt_ctx_init(&ctx);
	lines = ft_split(options, '\n');
	if (!lines)
		return (false);
	if (!parse_option_lines(t, lines, &ctx))
		return (false);
	if (!opt_ctx_complete(&ctx))
	{
		table_free(t);
		return (false);
	}
	return (true);
}
