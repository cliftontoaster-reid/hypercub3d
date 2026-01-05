/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peterpan.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:26:55 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/05 11:18:41 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils/vec.h"
#include <stdbool.h>
#define XK_MISCELLANY
#include <X11/keysymdef.h>

#define EVENT_KEY_PRESS 2L
#define EVENT_KEY_RELEASE 3L
#define EVENT_MOUSE_PRESS 4L
#define EVENT_MOUSE_RELEASE 5L
#define EVENT_MOUSE_MOVE 6L

#define MASK_KEY_PRESS 0x1L
#define MASK_KEY_RELEASE 0x2L
#define MASK_MOUSE_PRESS 0x4L
#define MASK_MOUSE_RELEASE 0x8L
#define MASK_MOUSE_MOVE 0x80000L

#define KEYS_COUNT 0xffff

typedef struct s_key_event
{
	/* keycode is implicit (index in the array) */
	void		(*on_press)(void *);
	void		(*on_release)(void *);
	void		*param;

}				t_key_event;

typedef struct s_keyboard_state
{
	bool		keys[KEYS_COUNT];
	t_key_event	events[KEYS_COUNT];
}				t_key_state;

t_key_state		*keyboard_init(void *mlx, void *win);
void			keyboard_update(t_key_state *k, int c, bool p);
bool			keyboard_is_pressed(t_key_state *k, int c);
void			keyboard_on_press(t_key_state *k, int c,
					void (*on_press)(void *), void *param);
void			keyboard_on_release(t_key_state *k, int c,
					void (*on_release)(void *), void *param);
void			keyboard_remove_events(t_key_state *k, int c);
void			keyboard_free(t_key_state *k);

typedef struct s_mouse_state
{
	t_vec2		pos;
	t_vec2		delta;
	bool		buttons[8];
}				t_mouse_state;

t_mouse_state	*mouse_init(void *mlx, void *win);
void			mouse_update_pos(t_mouse_state *m, int x, int y);
void			mouse_update_button(t_mouse_state *m, unsigned char b, bool p);
bool			mouse_is_button_pressed(t_mouse_state *m, unsigned char b);
t_vec2			mouse_get_delta(t_mouse_state *m);
t_vec2			mouse_get_position(t_mouse_state *m);
void			mouse_reset_delta(t_mouse_state *m);
