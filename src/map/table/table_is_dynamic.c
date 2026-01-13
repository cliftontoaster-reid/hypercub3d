/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_is_dynamic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:10:06 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/13 14:19:38 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/table.h"

bool	table_is_dynamic(t_table *table, size_t x, size_t y)
{
	uint8_t	data_idx;
	void	*data;

	if (x >= table->width || y >= table->height)
		return (false);
	if (x < 0 || y < 0)
		return (false);
	data_idx = table->cell_data_idx[y][x];
	data = table->cell_data[data_idx];
	return (data != NULL);
}
