/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_is_dynamic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:10:06 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/17 13:00:10 by mbores           ###   ########.fr       */
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