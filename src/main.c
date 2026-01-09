/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:25:00 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/08 12:48:17 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/render.h"
#include "map/minimap.h"
#include "map/table.h"
#include "utils/string.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char const *argv[])
{
	t_string	*content;
	t_table		*map;
	t_renderctx	*render;

	// t_window	*window;
	// t_holy_cow	*all;
	if (argc != 2)
	{
		fputs("Usage: ", stderr);
		fputs(argv[0], stderr);
		fputs(" <map_file>\n", stderr);
		return (1);
	}
	content = string_from_file(argv[1]);
	if (!content)
	{
		fputs("Error: Failed to read map file '", stderr);
		fputs(argv[1], stderr);
		fputs("'\n", stderr);
		return (1);
	}
	map = table_load(content->data);
	if (!map)
	{
		string_free(content);
		fputs("Error: Failed to load map\n", stderr);
		return (1);
	}
	string_free(content);
	render = render_init(map, v2i(800, 600));
	(void)render;
	// window = malloc(sizeof(t_window));
	// all = malloc(sizeof(t_holy_cow));
	// all->map = map;
	// all->window = window;
	printf("Map loaded successfully: %zux%zu\n", map->width, map->height);
	// init_window(all);
	// table_free(map);
	return (0);
}
