/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:23:56 by mbores            #+#    #+#             */
/*   Updated: 2025/12/23 16:27:24 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/image.h"
#include "mlx.h"
#include "table.h"
#include "utils/string.h"
#include "hooks/peterpan.h"
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
void				init_window(t_holy_cow *all);

// pixel_put.c
void				my_mlx_pixel_put(t_image *img, int x, int y, int color);

// display_player.c
void				display_player(t_holy_cow *all);

// display_map.c
void				display_map(t_holy_cow *all);

// key_handler.c
int					key_handler(int keycode, t_holy_cow *all);

// close_window.c
void				close_window(void *stuff);