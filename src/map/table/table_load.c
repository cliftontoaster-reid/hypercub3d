/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:10:48 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/09 14:14:26 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map/table.h"

size_t	find_last_empty_row(const char *content)
{
	size_t		last_non_empty_idx;
	size_t		current_idx;
	const char	*ptr = content;
	size_t		len;
	bool		is_empty;

	if (content == NULL)
		return (0);
	last_non_empty_idx = 0;
	current_idx = 0;
	while (*ptr)
	{
		len = 0;
		is_empty = true;
		while (ptr[len] && ptr[len] != '\n')
		{
			if (!ft_ciswhite(ptr[len]))
				is_empty = false;
			len++;
		}
		if (!is_empty)
			last_non_empty_idx = current_idx + len;
		current_idx += len;
		ptr += len;
		if (*ptr == '\n')
		{
			current_idx++;
			ptr++;
		}
	}
	return (last_non_empty_idx);
}

bool	table_load(t_table *table, const char *content)
{
	size_t	last_row;
	char	*options;
	char	*map;

	if (table == NULL || content == NULL)
		return (false);
	last_row = find_last_empty_row(content);
	if (last_row == 0)
		return (false);
	options = ft_substr(content, 0, last_row);
	if (!table_load_options(table, options))
	{
		free(options);
		return (false);
	}
	free(options);
	map = ft_substr(content, last_row, ft_strlen(content) - last_row);
	if (!table_load_map(table, map))
	{
		free(map);
		return (false);
	}
	free(map);
	return (true);
}
