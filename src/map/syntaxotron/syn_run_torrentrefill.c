/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syn_run_torrentrefill.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:14:59 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/22 11:50:35 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map/syntaxotron.h"
#include <stdlib.h>

static bool	syn_throw_pos_eternal_hell(t_torrentrefill *refill, t_vec2i pos,
		t_vec2i *out_leak)
{
	if (pos.x < 0 || pos.y < 0 || (size_t)pos.x >= refill->desk->width
		|| (size_t)pos.y >= refill->desk->height)
	{
		if (out_leak)
			*out_leak = pos;
		return (false);
	}
	if (refill->refilled[pos.y][pos.x])
		return (true);
	refill->refilled[pos.y][pos.x] = true;
	refill->to_refill[refill->refilllen++] = pos;
	return (true);
}

static bool	sncf(t_torrentrefill *refill, t_vec2i pos, t_vec2i *out_leak)
{
	if (refill->desk->cells[pos.y][pos.x] != '0')
		return (true);
	if (!syn_throw_pos_eternal_hell(refill, v2i(pos.x + 1, pos.y), out_leak))
		return (false);
	if (!syn_throw_pos_eternal_hell(refill, v2i(pos.x - 1, pos.y), out_leak))
		return (false);
	if (!syn_throw_pos_eternal_hell(refill, v2i(pos.x, pos.y + 1), out_leak))
		return (false);
	if (!syn_throw_pos_eternal_hell(refill, v2i(pos.x, pos.y - 1), out_leak))
		return (false);
	return (true);
}

static bool	syn_visit_disneyland(t_torrentrefill *refill, t_vec2i pos,
		t_vec2i *out_leak)
{
	if (pos.x < 0 || pos.y < 0 || (size_t)pos.x >= refill->desk->width
		|| (size_t)pos.y >= refill->desk->height)
	{
		if (out_leak)
			*out_leak = pos;
		return (false);
	}
	if (refill->desk->cells[pos.y][pos.x] == ' '
		|| refill->desk->cells[pos.y][pos.x] == '\0')
	{
		if (out_leak)
			*out_leak = pos;
		return (false);
	}
	return (sncf(refill, pos, out_leak));
}

bool	syn_run_torrentrefill(t_torrentrefill *refill, t_vec2i start_pos,
		t_vec2i *out_leak)
{
	size_t	idx;
	t_vec2i	pos;

	if (!refill || !refill->desk || !refill->to_refill || !refill->refilled)
		return (false);
	refill->refilllen = 0;
	if (!syn_throw_pos_eternal_hell(refill, start_pos, out_leak))
		return (false);
	idx = 0;
	while (idx < refill->refilllen)
	{
		pos = refill->to_refill[idx++];
		if (!syn_visit_disneyland(refill, pos, out_leak))
			return (false);
	}
	return (true);
}
