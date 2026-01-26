/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:03:27 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/21 14:06:14 by mbores           ###   ########.fr       */
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
	float		player_dir;

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

typedef struct s_parse_ctx
{
	size_t		x;
	size_t		y;
	bool		player_found;
}				t_parse_ctx;

typedef struct s_opt_ctx
{
	bool		no;
	bool		so;
	bool		we;
	bool		ea;
	bool		f;
	bool		c;
}				t_opt_ctx;

size_t			get_longest_row_length(const char *str);

size_t			find_last_empty_row(const char *content);
bool			find_split_pos(const char *content, size_t *opt_end);

t_table			*table_new(size_t width, size_t height, void *mlx);
t_table			*table_load(const char *content, void *mlx);
void			table_free(t_table *table);

bool			table_is_dynamic(t_table *table, size_t x, size_t y);
bool			table_is_walkable(t_table *table, size_t x, size_t y);
void			*table_get_cell_data(t_table *table, size_t x, size_t y);
bool			table_set_player_pos(t_table *table, size_t x, size_t y);
t_vec2i			table_get_player_pos(t_table *table);

bool			is_valid_cell_char(char c);
bool			is_player_char(char c);

void			opt_ctx_init(t_opt_ctx *c);
bool			opt_ctx_complete(t_opt_ctx *c);
bool			parse_rbg(const char *str, t_colour *out);
bool			ld(t_image **i, const char *p, t_table *t, bool *c);
bool			lrgb(t_colour *col, const char *s, t_table *t, bool *c);

bool			table_load_options(t_table *table, const char *options);
bool			table_parse_option_line(t_table *t, char *l, t_opt_ctx *c);
bool			table_is_space(char c);
bool			table_load_map(t_table *table, const char *map);
