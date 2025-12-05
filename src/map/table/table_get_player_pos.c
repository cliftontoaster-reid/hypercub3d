/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_get_player_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:10:01 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/04 15:10:03 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/table.h"

t_vec2i	table_get_player_pos(t_table *table)
{
	return (table->player_pos);
}