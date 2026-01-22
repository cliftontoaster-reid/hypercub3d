/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:25:00 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/22 12:07:02 by lfiorell         ###   ########.fr       */
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
	fputs("Usage: ", stderr);
	fputs(prog, stderr);
	fputs(" <map_file>\n", stderr);
	return (1);
}

static t_table	*load_map(const char *path, void *mlx)
{
	t_string	*content;
	t_table		*map;

	content = string_from_file(path);
	if (!content)
	{
		fputs("Error: Failed to read map file '\n", stderr);
		return (NULL);
	}
	map = table_load(content->data, mlx);
	string_free(content);
	if (!map)
		fputs("Error: Failed to load map\n", stderr);
	return (map);
}

static t_renderctx	*init_render(t_table *map, void *mlx)
{
	t_renderctx	*render;

	render = render_init(map, v2i(WIN_WIDTH, WIN_HEIGHT), mlx);
	if (!render)
		fputs("Error: Failed to initialize render context\n", stderr);
	return (render);
}

static int	run_game(t_table *map, void *mlx)
{
	t_renderctx	*render;

	render = init_render(map, mlx);
	if (!render)
	{
		table_free(map);
		return (1);
	}
	printf("Map loaded successfully: %zux%zu\n", map->width, map->height);
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_table	*map;
	void	*mlx;

	if (argc < 2 || argc > 3)
		return (print_usage(argv[0]));
	mlx = mlx_init();
	map = load_map(argv[1], mlx);
	if (!map)
	{
		mlx_destroy_display(mlx);
		free(mlx);
		return (1);
	}
	if (argc == 3 && ft_strcmp(argv[2], "--check") == 0)
	{
		printf("Map is valid.\n");
		table_free(map);
		mlx_destroy_display(mlx);
		free(mlx);
		return (0);
	}
	return (run_game(map, mlx));
}
