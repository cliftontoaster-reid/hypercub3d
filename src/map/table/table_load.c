/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:10:48 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/05 13:52:17 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map/table.h"

static void	table_if_player(t_table *table, size_t x, size_t y,
		const char *content)
{
	if (*content == TABLE_CELL_PLAYER_N || *content == TABLE_CELL_PLAYER_S
		|| *content == TABLE_CELL_PLAYER_E || *content == TABLE_CELL_PLAYER_W)
	{
		table->player_pos.x = x;
		table->player_pos.y = y;
	}
}

size_t	find_last_empty_row(const char *content)
{
	size_t		last_empty_row;
	size_t		current_row;
	const char	*ptr = content;
	size_t		len;
	bool		is_empty;

	if (content == NULL)
		return (0);
	last_empty_row = 0;
	current_row = 0;
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
			last_empty_row = current_row;
		current_row++;
		ptr += len;
		if (*ptr == '\n')
			ptr++;
	}
	return (last_empty_row);
}

bool	table_load(t_table *table, const char *content)
{
	if (table == NULL || content == NULL)
		return (false);
}
