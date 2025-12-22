/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:42:10 by mbores            #+#    #+#             */
/*   Updated: 2025/12/22 14:34:47 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/minimap.h"

void    player_square(t_holy_cow *all, int player_x, int player_y, int color)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < 5)
    {
        while (x < 5)
        {
            my_mlx_pixel_put(all->window->image,
                player_x + 13 + x, player_y + 13 + y, color);
            x++;
        }
        x = 0;
        y++;
    }
}

void    display_player(t_holy_cow *all)
{
    int     color;
    int     player_x;
    int     player_y;

    player_x = all->map->player_pos.x * 32 - 16;
    player_y = all->map->player_pos.y * 32 - 16;
    color = c(rgb(255, 0, 0));
    player_square(all, player_x, player_y, color);
}