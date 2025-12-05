/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_is_walkable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:10:27 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/04 15:10:37 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/table.h"

bool	table_is_walkable(t_table *table, size_t x, size_t y)
{
	char	cell;

	if (x >= table->width || y >= table->height)
		return (false);
	if (x < 0 || y < 0)
		return (false);
	cell = table->cells[y][x];
	return (cell == TABLE_CELL_FLOOR || cell == TABLE_CELL_PLAYER_N
		|| cell == TABLE_CELL_PLAYER_S || cell == TABLE_CELL_PLAYER_E
		|| cell == TABLE_CELL_PLAYER_W);
}
