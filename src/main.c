/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:25:00 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/14 14:29:10 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/render.h"
#include "map/minimap.h"
#include "map/table.h"
#include "utils/string.h"
#include <stdio.h>
#include <stdlib.h>

static int	print_usage(const char *prog)
{
	printf("Usage: %s <map_file>\n", prog);
	return (1);
}

static t_table	*load_map(const char *path, void *mlx)
{
	t_string	*content;
	t_table		*map;

	content = string_from_file(path);
	if (!content)
	{
		printf("Error: Failed to read map file '%s'\n", path);
		return (NULL);
	}
	map = table_load(content->data, mlx);
	string_free(content);
	if (!map)
		printf("Error: Failed to load map\n");
	return (map);
}

static t_renderctx	*init_render(t_table *map, void *mlx)
{
	t_renderctx	*render;

	render = render_init(map, v2i(WIN_WIDTH, WIN_HEIGHT), mlx);
	if (!render)
		printf("Error: Failed to initialize render context\n");
	return (render);
}

int	main(int argc, char const *argv[])
{
	t_table		*map;
	t_renderctx	*render;
	void		*mlx;

	if (argc != 2)
		return (print_usage(argv[0]));
	mlx = mlx_init();
	map = load_map(argv[1], mlx);
	if (!map)
		return (1);
	render = init_render(map, mlx);
	if (!render)
	{
		table_free(map);
		return (1);
	}
	printf("Map loaded successfully: %zux%zu\n", map->width, map->height);
	return (0);
}
