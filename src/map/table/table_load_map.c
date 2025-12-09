/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_load_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:04:51 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/09 14:07:16 by lfiorell         ###   ########.fr       */
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
				table->cells[y][x] = map[i];
			else
			{
				if (is_player_char(map[i]) && player_found)
					return (false);
				table->cells[y][x] = '0';
				table->player_pos.x = x;
				table->player_pos.y = y;
				player_found = true;
			}
		}
		x++;
	}
	return (player_found);
}
