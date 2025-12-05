/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_is_dynamic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:10:06 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/04 15:10:13 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/table.h"

bool	table_is_dynamic(t_table *table, size_t x, size_t y)
{
	if (x >= table->width || y >= table->height)
		return (false);
	if (x < 0 || y < 0)
		return (false);
	uint8_t data_idx = table->cell_data_idx[y][x];
	void *data = table->cell_data[data_idx];
	return (data != NULL);
}