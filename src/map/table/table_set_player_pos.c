/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_set_player_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:19:46 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/04 15:20:13 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/table.h"

bool	table_set_player_pos(t_table *table, size_t x, size_t y)
{
	t_vec2i	pos;

	if (x >= table->width || y >= table->height)
		return (false);
	if (x < 0 || y < 0)
		return (false);
	pos.x = x;
	pos.y = y;
	table->player_pos = pos;
	return (true);
}
