/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_get_cell_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:09:35 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/13 14:17:16 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/table.h"

void	*table_get_cell_data(t_table *table, size_t x, size_t y)
{
	if (x >= table->width || y >= table->height)
		return (NULL);
	if (x < 0 || y < 0)
		return (NULL);
	return (table->cell_data[table->cell_data_idx[y][x]]);
}
