/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syn_run_torrentrefill.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:14:59 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/05 11:29:55 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map/syntaxotron.h"
#include <stdlib.h>

static bool	syn_throw_pos_eternal_hell(t_torrentrefill *refill, t_vec2i pos)
{
	if (pos.x < 0 || pos.y < 0 || (size_t)pos.x >= refill->desk->width
		|| (size_t)pos.y >= refill->desk->height)
		return (false);
	if (refill->refilled[pos.y][pos.x])
		return (true);
	refill->to_refill[refill->refilllen++] = pos;
	return (true);
}

static bool	syn_visit_disneyland(t_torrentrefill *refill, t_vec2i pos)
{
	if (pos.x < 0 || pos.y < 0 || (size_t)pos.x >= refill->desk->width
		|| (size_t)pos.y >= refill->desk->height)
		return (false);
	if (refill->refilled[pos.y][pos.x])
		return (true);
	refill->refilled[pos.y][pos.x] = true;
	if (refill->desk->cells[pos.y][pos.x] == ' ')
		return (false);
	if (refill->desk->cells[pos.y][pos.x] != '0')
		return (true);
	// Add neighboring positions to to_refill list
	syn_throw_pos_eternal_hell(refill, v2i(pos.x + 1, pos.y));
	syn_throw_pos_eternal_hell(refill, v2i(pos.x - 1, pos.y));
	syn_throw_pos_eternal_hell(refill, v2i(pos.x, pos.y + 1));
	syn_throw_pos_eternal_hell(refill, v2i(pos.x, pos.y - 1));
	return (true);
}

bool	syn_run_torrentrefill(t_torrentrefill *refill, t_vec2i start_pos)
{
	size_t	idx;
	t_vec2i	pos;

	if (!refill || !refill->desk || !refill->to_refill || !refill->refilled)
		return (false);
	refill->refilllen = 0;
	if (!syn_throw_pos_eternal_hell(refill, start_pos))
		return (false);
	idx = 0;
	while (idx < refill->refilllen)
	{
		pos = refill->to_refill[idx++];
		if (!syn_visit_disneyland(refill, pos))
			return (false);
	}
	return (true);
}
