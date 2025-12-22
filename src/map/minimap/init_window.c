/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:23:36 by mbores            #+#    #+#             */
/*   Updated: 2025/12/22 14:23:22 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/minimap.h"

void    init_window(t_holy_cow *all)
{
    all->window->mlx = mlx_init();
    all->window->mlx_win = mlx_new_window(all->window->mlx,
        all->map->width * 32, all->map->height * 32, "Hypercube3D");
    all->window->image = image_new(all->window->mlx,
        all->map->width * 32, all->map->height * 32);
    display_map(all);
    display_player(all);
    mlx_hook(all->window->mlx_win, 17, 1L << 17, close_window, all);
    mlx_hook(all->window->mlx_win, 02, 1L << 0, key_handler, all);
    mlx_loop(all->window->mlx);
}
