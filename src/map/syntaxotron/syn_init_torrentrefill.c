/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syn_init_torrentrefill.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:14:59 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/05 11:29:55 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map/syntaxotron.h"
#include "utils/torrentrefill.h"
#include <stdlib.h>

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
