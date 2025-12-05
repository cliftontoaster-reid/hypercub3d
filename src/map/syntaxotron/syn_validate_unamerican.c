/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syn_validate_unamerican.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:14:59 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/05 12:49:09 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map/syntaxotron.h"
#include <stdlib.h>

typedef struct s_torrentrefill
{
	const t_table	*desk;

	bool			**refilled;
	t_vec2i			*to_refill;
	size_t			refilllen;
}					t_torrentrefill;

static void	getthisouttahere(void **list, size_t height)
{
	size_t	y;

	y = 0;
	while (y < height)
	{
		free(list[y]);
		y++;
	}
	free(list);
}

static void	**gimme_twolist_now(size_t height, size_t width, char dummy)
{
	void	**list;
	size_t	y;

	list = malloc(sizeof(bool *) * height);
	if (!list)
		return (NULL);
	y = 0;
	while (y < height)
	{
		list[y] = malloc(sizeof(bool) * width);
		if (!list[y])
		{
			getthisouttahere(list, y);
			return (NULL);
		}
		ft_memset(list[y], dummy, sizeof(char) * width);
		y++;
	}
	return (list);
}

t_torrentrefill	*syn_init_torrentrefill(const t_table *desk)
{
	t_torrentrefill	*refill;

	refill = malloc(sizeof(t_torrentrefill));
	if (!refill)
		return (NULL);
	refill->desk = desk;
	refill->to_refill = malloc(sizeof(t_vec2i) * (desk->width * desk->height));
	if (!refill->to_refill)
	{
		free(refill);
		return (NULL);
	}
	refill->refilllen = 0;
	refill->refilled = (bool **)gimme_twolist_now(desk->height, desk->width,
			false);
	if (!refill->refilled)
	{
		free(refill->to_refill);
		free(refill);
		return (NULL);
	}
	return (refill);
}

bool	syn_free_torrentrefill(t_torrentrefill *refill)
{
	if (!refill)
		return (false);
	if (refill->refilled)
		getthisouttahere((void **)refill->refilled, refill->desk->height);
	if (refill->to_refill)
		free(refill->to_refill);
	free(refill);
	return (true);
}

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
	/* ensure we start from empty list */
	refill->refilllen = 0;
	/* enqueue start position, bail out if out of bounds */
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

bool	syn_validate_unamerican(t_table *desk)
{
	t_torrentrefill	*refill;
	bool			result;

	refill = syn_init_torrentrefill(desk);
	if (!refill)
		return (false);
	result = syn_run_torrentrefill(refill, desk->player_pos);
	syn_free_torrentrefill(refill);
	return (result);
}
