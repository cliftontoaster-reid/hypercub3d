/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_load_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:05:49 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/19 16:17:07 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/colour.h"
#include "graphics/image.h"
#include "libft.h"
#include "map/table.h"

#define CMP ft_strncmp

static void	opt_ctx_init(t_opt_ctx *c)
{
	ft_bzero(c, sizeof(t_opt_ctx));
}

static bool	opt_ctx_complete(t_opt_ctx *c)
{
	return (c->no && c->so && c->we && c->ea && c->f && c->c);
}

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

bool	table_load_options(t_table *t, const char *options)
{
	t_opt_ctx	ctx;
	char		**lines;
	int			i;

	if (!t || !options)
		return (false);
	opt_ctx_init(&ctx);
	lines = ft_split(options, '\n');
	if (!lines)
		return (false);
	i = 0;
	while (lines[i])
	{
		if (!parse_option_line(t, lines[i], &ctx))
		{
			free_lines(lines);
			return (false);
		}
		i++;
	}
	free_lines(lines);
	if (!opt_ctx_complete(&ctx))
	{
		table_free(t);
		return (false);
	}
	return (true);
}
