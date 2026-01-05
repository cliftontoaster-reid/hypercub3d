/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:42:10 by mbores            #+#    #+#             */
/*   Updated: 2026/01/05 11:18:22 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/colour.h"
#include "map/minimap.h"

void	player_square(t_holy_cow *all, int player_x, int player_y,
		t_colour color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 5)
	{
		while (x < 5)
		{
			image_put_pixel(all->window->image, player_x + 13 + x, player_y + 13
				+ y, c(color));
			x++;
		}
		x = 0;
		y++;
	}
}

void	display_player(t_holy_cow *all)
{
	t_colour	color;
	int			player_x;
	int			player_y;

	player_x = all->map->player_pos.x * 32 - 16;
	player_y = all->map->player_pos.y * 32 - 16;
	color = rgb(255, 0, 0);
	player_square(all, player_x, player_y, color);
}
