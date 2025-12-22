/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_load_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:04:51 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/17 13:55:03 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map/table.h"

static bool	is_valid_cell_char(char c)
{
	return (c == TABLE_CELL_EMPTY || c == TABLE_CELL_WALL
		|| c == TABLE_CELL_FLOOR || c == TABLE_CELL_PLAYER_N
		|| c == TABLE_CELL_PLAYER_S || c == TABLE_CELL_PLAYER_E
		|| c == TABLE_CELL_PLAYER_W);
}

static bool	is_player_char(char c)
{
	return (c == TABLE_CELL_PLAYER_N || c == TABLE_CELL_PLAYER_S
		|| c == TABLE_CELL_PLAYER_E || c == TABLE_CELL_PLAYER_W);
}

bool	table_load_map(t_table *table, const char *map)
{
	size_t	i;
	size_t	y;
	size_t	x;
	bool	player_found;

	i = 0;
	y = 0;
	x = 0;
	player_found = false;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			y++;
			x = 0;
		}
		else
		{
			if (!is_valid_cell_char(map[i]))
				return (false);
			if (!table->cells || !table->cells[y] || x >= table->width)
				return (false);
			if (is_player_char(map[i]))
			{
				if (player_found)
					return (false);
				table->cells[y][x] = '0';
				table->player_pos.x = x;
				table->player_pos.y = y;
				player_found = true;
			}
			else
				table->cells[y][x] = map[i];
			x++;
		}
		i++;
	}
	return (player_found);
}
