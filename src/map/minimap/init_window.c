/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:23:36 by mbores            #+#    #+#             */
/*   Updated: 2026/01/08 12:50:37 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/minimap.h"
#define XK_MISCELLANY
#include <X11/keysymdef.h>

// int	close_window_worse(void *stuff)
// {
// 	close_window(stuff);
// 	return (69420);
// }

// void	init_window(t_renderctx *render)
// {
// 	display_map(render);
// 	display_player(render);
// 	render->keyboard = keyboard_init(render->mlx, render->win);
// 	render->mouse = mouse_init(render->mlx, render->win);
// 	keyboard_on_press(render->keyboard, XK_Escape, close_window, render);
// 	mlx_hook(render->win, 17, 1L << 17, close_window_worse, render);
// 	mlx_loop(render->mlx);
// }
