/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:10:48 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/10 13:39:00 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map/table.h"

size_t	find_last_empty_row(const char *content)
{
	size_t		current_idx;
	const char	*ptr = content;
	size_t		len;
	bool		is_empty;
	size_t		pos;

	if (content == NULL)
		return (0);
	current_idx = 0;
	while (*ptr)
	{
		len = 0;
		is_empty = true;
		while (ptr[len] && ptr[len] != '\n')
		{
			if (!ft_ciswhite((unsigned char)ptr[len]))
				is_empty = false;
			len++;
		}
		if (is_empty)
		{
			pos = current_idx + len;
			if (ptr[len] == '\n')
				pos++;
			if (content[pos] != '\0')
				return (pos);
			return (0);
		}
		current_idx += len;
		ptr += len;
		if (*ptr == '\n')
		{
			current_idx++;
			ptr++;
		}
	}
	return (0);
}

t_table	*table_load(const char *content)
{
	t_table		*table;
	size_t		last_row;
	char		*options;
	char		*map;
	size_t		width;
	size_t		height;
	const char	*ptr;

	if (content == NULL)
		return (NULL);
	last_row = find_last_empty_row(content);
	if (last_row == 0)
		return (NULL);
	options = ft_substr(content, 0, last_row);
	map = ft_substr(content, last_row, ft_strlen(content) - last_row);
	if (!options || !map)
	{
		free(options);
		free(map);
		return (NULL);
	}
	width = get_longest_row_length(map);
	/* compute height (number of rows) */
	height = 0;
	ptr = map;
	while (*ptr)
	{
		height++;
		while (*ptr && *ptr != '\n')
			ptr++;
		if (*ptr == '\n')
			ptr++;
	}
	table = table_new(width, height);
	if (!table)
	{
		free(options);
		free(map);
		return (NULL);
	}
	if (!table_load_options(table, options))
	{
		free(options);
		table_free(table);
		free(map);
		return (NULL);
	}
	free(options);
	if (!table_load_map(table, map))
	{
		free(map);
		table_free(table);
		return (NULL);
	}
	free(map);
	return (table);
}
