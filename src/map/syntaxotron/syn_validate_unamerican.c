/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syn_validate_unamerican.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:14:59 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/22 13:40:03 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map/syntaxotron.h"
#include "utils/error.h"
#include <stdlib.h>

static bool	check_cell(t_torrentrefill *refill, t_table *desk,
	size_t y, size_t x)
{
	char	c;
	t_vec2i	leak_pos;

	c = desk->cells[y][x];
	if ((c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		&& !refill->refilled[y][x])
	{
		leak_pos = v2i(x, y);
		if (!syn_run_torrentrefill(refill, leak_pos, &leak_pos))
			return (false);
	}
	return (true);
}

static bool	check_map_fill(t_torrentrefill *refill, t_table *desk)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < desk->height)
	{
		x = 0;
		while (x < desk->width)
		{
			if (!check_cell(refill, desk, y, x))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

bool	syn_validate_unamerican(t_table *desk)
{
	t_torrentrefill	*refill;
	bool			result;
	t_vec2i			leak_pos;

	refill = syn_init_torrentrefill(desk);
	if (!refill)
		return (false);
	leak_pos = desk->player_pos;
	result = syn_run_torrentrefill(refill, desk->player_pos, &leak_pos);
	if (result)
		result = check_map_fill(refill, desk);
	syn_free_torrentrefill(refill);
	if (!result)
		err_print_context(desk, leak_pos, 5, SYN_ERR_MAP_NOT_CLOSED);
	return (result);
}
