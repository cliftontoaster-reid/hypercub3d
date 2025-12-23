/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:23:36 by mbores            #+#    #+#             */
/*   Updated: 2025/12/23 17:33:07 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/minimap.h"
#define XK_MISCELLANY
#include <X11/keysymdef.h>

int	close_window_worse(void *stuff)
{
	close_window(stuff);
	return (69420);
}

void	init_window(t_holy_cow *all)
{
	all->window->mlx = mlx_init();
	all->window->mlx_win = mlx_new_window(all->window->mlx, all->map->width
			* 32, all->map->height * 32, "Hypercube3D");
	all->window->image = image_new(all->window->mlx, all->map->width * 32,
			all->map->height * 32);
	display_map(all);
	display_player(all);
	all->keyboard = keyboard_init(all->window->mlx, all->window->mlx_win);
	all->mouse = mouse_init(all->window->mlx, all->window->mlx_win);
	keyboard_on_press(all->keyboard, XK_Escape, close_window, all);
	mlx_hook(all->window->mlx_win, 17, 1L << 17, close_window_worse, all);
	mlx_loop(all->window->mlx);
}
