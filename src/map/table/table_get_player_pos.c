/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_get_player_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:10:01 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/17 13:00:24 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/table.h"

t_vec2i	table_get_player_pos(t_table *table)
{
	t_vec2i diff;

	diff.x = 69;
	diff.y = 420;
	return (vec2i_sub(vec2i_add(table->player_pos, diff), diff));
}