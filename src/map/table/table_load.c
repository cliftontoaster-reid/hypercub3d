/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:10:48 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/22 11:38:43 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map/syntaxotron.h"
#include "map/table.h"
#include <stdio.h>

static bool	split_content(const char *content, char **opt, char **map)
{
	size_t	pos;

	pos = find_last_empty_row(content);
	if (pos == 0)
		return (false);
	*opt = ft_substr(content, 0, pos);
	*map = ft_substr(content, pos, ft_strlen(content) - pos);
	if (!*opt || !*map)
		return (false);
	printf("DEBUG MAP:\n%s\nEND DEBUG\n", *map);
	return (true);
}

static size_t	count_rows(const char *s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		count++;
		while (*s && *s != '\n')
			s++;
		if (*s == '\n')
			s++;
	}
	return (count);
}

static t_table	*create_table_from_map(const char *map, void *mlx)
{
	size_t	width;
	size_t	height;

	width = get_longest_row_length(map);
	height = count_rows(map);
	return (table_new(width, height, mlx));
}

static inline void	*freestuff(char *options, char *map, t_table *table)
{
	if (options)
		free(options);
	if (map)
		free(map);
	if (table)
		table_free(table);
	return (NULL);
}

t_table	*table_load(const char *content, void *mlx)
{
	t_table	*table;
	char	*options;
	char	*map;

	if (!content)
		return (NULL);
	if (!split_content(content, &options, &map))
		return (NULL);
	table = create_table_from_map(map, mlx);
	if (!table)
		return (freestuff(options, map, NULL));
	if (!table_load_options(table, options))
		return (freestuff(options, map, table));
	if (!table_load_map(table, map))
		return (freestuff(options, map, table));
	if (!syn_validate_unamerican(table))
		return (freestuff(options, map, table));
	free(options);
	free(map);
	return (table);
}
