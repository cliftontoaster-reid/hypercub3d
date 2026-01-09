/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:23:56 by mbores            #+#    #+#             */
/*   Updated: 2026/01/08 14:40:39 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "graphics/image.h"
#include "graphics/render.h"
#include "hooks/peterpan.h"
#include "mlx.h"
#include "table.h"
#include "utils/string.h"
#include <stdlib.h>

typedef struct s_window
{
	void			*mlx;
	void			*mlx_win;
	t_image			*image;
}					t_window;

typedef struct s_holy_cow
{
	t_table			*map;
	t_window		*window;
	t_key_state		*keyboard;
	t_mouse_state	*mouse;
}					t_holy_cow;

// init_window.c
void				init_window(t_renderctx *render);

// pixel operations are declared in `graphics/image.h`

// display_minimap.c
void				display_minimap(t_renderctx *ctx);

// key_handler.c
int					key_handler(int keycode, t_holy_cow *all);

// close_window.c
void				close_window(void *stuff);
