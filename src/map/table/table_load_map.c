/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_load_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:04:51 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/19 16:42:51 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map/table.h"
#include <math.h>
#include <stdio.h>

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

static float	player_dir_from_char(char c)
{
	if (c == TABLE_CELL_PLAYER_N)
		return (0.0f);
	if (c == TABLE_CELL_PLAYER_S)
		return ((float)M_PI);
	if (c == TABLE_CELL_PLAYER_E)
		return ((float)(M_PI / 2));
	if (c == TABLE_CELL_PLAYER_W)
		return ((float)(3 * M_PI / 2));
	return (-1.0f);
}

static bool	handle_player(t_table *t, char c, t_parse_ctx *ctx)
{
	float	dir;

	if (ctx->player_found)
		return (false);
	dir = player_dir_from_char(c);
	if (dir < 0)
		return (false);
	t->cells[ctx->y][ctx->x] = '0';
	t->player_pos.x = ctx->x;
	t->player_pos.y = ctx->y;
	t->player_dir = dir;
	ctx->player_found = true;
	return (true);
}

static bool	write_cell(t_table *t, char c, t_parse_ctx *ctx)
{
	if (!is_valid_cell_char(c))
		return (false);
	if (!t->cells || !t->cells[ctx->y] || ctx->x >= t->width)
		return (false);
	if (is_player_char(c))
		return (handle_player(t, c, ctx));
	t->cells[ctx->y][ctx->x] = c;
	return (true);
}

static void	end_row(t_table *t, t_parse_ctx *ctx)
{
	t->cells[ctx->y][ctx->x] = '\0';
	ctx->y++;
	ctx->x = 0;
}

bool	table_load_map(t_table *table, const char *map)
{
	t_parse_ctx	ctx;
	size_t		i;

	ctx.x = 0;
	ctx.y = 0;
	ctx.player_found = false;
	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			end_row(table, &ctx);
		else
		{
			if (!write_cell(table, map[i], &ctx))
				return (false);
			ctx.x++;
		}
		i++;
	}
	if (ctx.y == table->height - 1)
		table->cells[ctx.y][ctx.x] = '\0';
	return (ctx.player_found);
}
