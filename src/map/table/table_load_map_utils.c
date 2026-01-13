/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_load_map_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:32:39 by mbores            #+#    #+#             */
/*   Updated: 2026/01/13 14:33:23 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map/table.h"

bool	is_valid_cell_char(char c)
{
	return (c == TABLE_CELL_EMPTY || c == TABLE_CELL_WALL
		|| c == TABLE_CELL_FLOOR || c == TABLE_CELL_PLAYER_N
		|| c == TABLE_CELL_PLAYER_S || c == TABLE_CELL_PLAYER_E
		|| c == TABLE_CELL_PLAYER_W);
}

bool	is_player_char(char c)
{
	return (c == TABLE_CELL_PLAYER_N || c == TABLE_CELL_PLAYER_S
		|| c == TABLE_CELL_PLAYER_E || c == TABLE_CELL_PLAYER_W);
}
