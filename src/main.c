/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:25:00 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/17 16:58:25 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/table.h"
#include "map/minimap.h"
#include "utils/string.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char const *argv[])
{
	t_string	*content;
	t_table		*map;
	t_window	*window;
	t_holy_cow	*all;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	content = string_from_file(argv[1]);
	if (!content)
	{
		fprintf(stderr, "Error: Failed to read map file '%s'\n", argv[1]);
		return (1);
	}
	map = table_load(content->data);
	if (!map)
	{
		string_free(content);
		fprintf(stderr, "Error: Failed to load map\n");
		return (1);
	}
	string_free(content);
	window = malloc(sizeof(t_window));
	all = malloc(sizeof(t_holy_cow));
	all->map = map;
	all->window = window;
	all->content = content;
	printf("Map loaded successfully: %zux%zu\n", map->width, map->height);
	init_window(all);
	// table_free(map);
	return (0);
}
