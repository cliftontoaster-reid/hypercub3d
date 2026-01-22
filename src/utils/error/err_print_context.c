/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_print_context.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:28:28 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/22 11:45:12 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/error.h"

static void	print_single_cell(const t_table *map, int x, int y, t_vec2i target)
{
	if (x < 0 || x >= (int)map->width || y < 0 || y >= (int)map->height)
	{
		if (x == target.x && y == target.y)
			printf(ERR_BG_RED " " ERR_COL_RESET);
		else
			printf(ERR_COL_RED " " ERR_COL_RESET);
		return ;
	}
	if (x == target.x && y == target.y)
		printf(ERR_BG_RED "%c" ERR_COL_RESET, map->cells[y][x]);
	else
		printf("%s%c" ERR_COL_RESET, err_get_char_colour(map->cells[y][x]),
			map->cells[y][x]);
}

static void	print_row_loop(const t_table *map, int y, int radius,
		t_vec2i center)
{
	int	i;
	int	x;
	int	limit;

	i = 0;
	limit = radius * 2 + 1;
	while (i < limit)
	{
		x = center.x - radius + i;
		print_single_cell(map, x, y, center);
		i++;
	}
	printf("\n");
}

void	err_print_context(const t_table *map, t_vec2i pos, int radius,
		const char *msg)
{
	int	i;
	int	y;
	int	limit;

	err_msg("syntaxotron", msg);
	i = 0;
	limit = radius * 2 + 1;
	while (i < limit)
	{
		y = pos.y - radius + i;
		print_row_loop(map, y, radius, pos);
		i++;
	}
}
