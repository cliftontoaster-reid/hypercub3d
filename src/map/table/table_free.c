/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:05:04 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/04 15:46:51 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/table.h"
#include <stdlib.h>

static void	table_free_cell_data(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < 256)
	{
		if (table->cell_data[i] != NULL)
		{
			free(table->cell_data[i]);
			table->cell_data[i] = NULL;
		}
		i++;
	}
}

static void	table_free_data_idx(t_table *table)
{
	size_t	y;

	if (table->cell_data_idx != NULL)
	{
		y = 0;
		while (y < table->height)
		{
			if (table->cell_data_idx[y] != NULL)
			{
				free(table->cell_data_idx[y]);
				table->cell_data_idx[y] = NULL;
			}
			y++;
		}
		free(table->cell_data_idx);
		table->cell_data_idx = NULL;
	}
}

static void	table_free_cells(t_table *table)
{
	size_t	y;

	if (table->cells != NULL)
	{
		y = 0;
		while (y < table->height)
		{
			if (table->cells[y] != NULL)
			{
				free(table->cells[y]);
				table->cells[y] = NULL;
			}
			y++;
		}
		free(table->cells);
		table->cells = NULL;
	}
}

void	table_free(t_table *table)
{
	table_free_data_idx(table);
	table_free_cell_data(table);
	table_free_cells(table);
	if (table->no_wall != NULL)
		image_free(table->no_wall);
	if (table->so_wall != NULL)
		image_free(table->so_wall);
	if (table->we_wall != NULL)
		image_free(table->we_wall);
	if (table->ea_wall != NULL)
		image_free(table->ea_wall);
	free(table);
}
