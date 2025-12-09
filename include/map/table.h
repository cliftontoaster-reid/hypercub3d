/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:03:27 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/09 14:14:56 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "graphics/colour.h"
#include "graphics/image.h"
#include "utils/vec.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef enum e_table_cell_type
{
	TABLE_CELL_EMPTY = ' ',
	TABLE_CELL_WALL = '1',
	TABLE_CELL_FLOOR = '0',
	TABLE_CELL_PLAYER_N = 'N',
	TABLE_CELL_PLAYER_S = 'S',
	TABLE_CELL_PLAYER_E = 'E',
	TABLE_CELL_PLAYER_W = 'W',
}				t_table_cell_type;

typedef struct s_table
{
	size_t		width;
	size_t		height;

	t_vec2i		player_pos;

	t_image		*no_wall;
	t_image		*so_wall;
	t_image		*we_wall;
	t_image		*ea_wall;
	t_colour	floor_col;
	t_colour	ceil_col;

	char		**cells;
	uint8_t		**cell_data_idx;

	void		*cell_data[256];
	uint8_t		data_idx;

	void		*mlx;
}				t_table;

size_t			get_longest_row_length(const char *str);

t_table			*table_new(size_t width, size_t height);
bool			table_load(t_table *table, const char *content);
void			table_free(t_table *table);

bool			table_is_dynamic(t_table *table, size_t x, size_t y);
bool			table_is_walkable(t_table *table, size_t x, size_t y);
void			*table_get_cell_data(t_table *table, size_t x, size_t y);
bool			table_set_player_pos(t_table *table, size_t x, size_t y);
t_vec2i			table_get_player_pos(t_table *table);

bool			table_load_options(t_table *table, const char *options);
bool			table_load_map(t_table *table, const char *map);
