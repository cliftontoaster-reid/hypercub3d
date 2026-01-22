/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syn_validate_unamerican.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:14:59 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/05 11:28:50 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map/syntaxotron.h"
#include "utils/error.h"
#include <stdlib.h>

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
	{
		size_t y = 0;
		while (y < desk->height)
		{
			size_t x = 0;
			while (x < desk->width)
			{
				char c = desk->cells[y][x];
				if ((c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
					&& !refill->refilled[y][x])
				{
					leak_pos = v2i(x, y);
					if (!syn_run_torrentrefill(refill, leak_pos, &leak_pos))
					{
						result = false;
						break ;
					}
				}
				x++;
			}
			if (!result)
				break ;
			y++;
		}
	}
	syn_free_torrentrefill(refill);
	if (!result)
		err_print_context(desk, leak_pos, 5, SYN_ERR_MAP_NOT_CLOSED);
	return (result);
}
