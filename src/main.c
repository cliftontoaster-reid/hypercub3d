/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:25:00 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/09 15:15:34 by lfiorell         ###   ########.fr       */
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
	void		*mlx;

	// t_window	*window;
	// t_holy_cow	*all;
	if (argc != 2)
	{
		fputs("Usage: ", stderr);
		fputs(argv[0], stderr);
		fputs(" <map_file>\n", stderr);
		return (1);
	}
	mlx = mlx_init();
	content = string_from_file(argv[1]);
	if (!content)
	{
		fputs("Error: Failed to read map file '", stderr);
		fputs(argv[1], stderr);
		fputs("'\n", stderr);
		return (1);
	}
	map = table_load(content->data, mlx);
	if (!map)
	{
		string_free(content);
		fputs("Error: Failed to load map\n", stderr);
		return (1);
	}
	string_free(content);
	render = render_init(map, v2i(WIN_WIDTH, WIN_HEIGHT), mlx);
	if (!render)
	{
		table_free(map);
		fputs("Error: Failed to initialize render context\n", stderr);
		return (1);
	}
	(void)render;
	printf("Map loaded successfully: %zux%zu\n", map->width, map->height);
	return (0);
}
