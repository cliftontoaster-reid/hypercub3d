/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:12:22 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/09 15:12:53 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map/table.h"
#include "mlx.h"

static bool	table_alloc_cells(t_table *table, size_t height, size_t width)
{
	size_t	y;

	table->cells = malloc(sizeof(char *) * height);
	if (table->cells == NULL)
	{
		free(table);
		return (NULL);
	}
	y = 0;
	while (y < height)
	{
		table->cells[y] = malloc(sizeof(char) * width);
		if (table->cells[y] == NULL)
		{
			table_free(table);
			return (false);
		}
		y++;
	}
	return (true);
}

static bool	table_alloc_cell_data_idx(t_table *table, size_t height,
		size_t width)
{
	size_t	y;

	table->cell_data_idx = malloc(sizeof(uint8_t *) * height);
	if (table->cell_data_idx == NULL)
	{
		table_free(table);
		return (false);
	}
	y = 0;
	while (y < height)
	{
		table->cell_data_idx[y] = malloc(sizeof(uint8_t) * width);
		if (table->cell_data_idx[y] == NULL)
		{
			table_free(table);
			return (false);
		}
		y++;
	}
	return (true);
}

t_table	*table_new(size_t width, size_t height, void *mlx)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (table == NULL)
		return (NULL);
	ft_bzero(table, sizeof(t_table));
	table->width = width;
	table->height = height;
	if (!table_alloc_cells(table, height, width))
		return (NULL);
	if (!table_alloc_cell_data_idx(table, height, width))
		return (NULL);
	table->mlx = mlx;
	if (table->mlx == NULL)
	{
		table_free(table);
		return (NULL);
	}
	return (table);
}
