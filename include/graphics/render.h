/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:28:25 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/05 12:45:33 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "graphics/image.h"
#include "graphics/raycast.h"
#include "hooks/peterpan.h"
#include "libft.h"
#include <stdbool.h>

typedef struct s_renderctx
{
	t_image			*buffer;
	t_table			*map;
	t_vec2			*pos;
	float			*dir;

	void			*mlx;
	void			*win;

	t_key_state		*keyboard;
	t_mouse_state	*mouse;
}					t_renderctx;

/*
 * @brief Initializes the render context, setting up the image buffer
 *        and window.
 * @param map The game map.
 * @param mlx The Minilibx instance.
 * @param win_size The size of the window.
 * @return The initialized render context if successful, NULL otherwise.
 */
t_renderctx			*render_init(t_table *map, void *mlx, t_vec2i win_size);

/*
 * @brief Updates the player's movement and rotation based on input.
 * @param ctx The render context containing player and input states.
 * @param delta_time The time elapsed since the last frame,
 *        for frame-rate independent movement.
 */
void				render_update(t_renderctx *ctx, float delta_time);

/*
 * @brief Renders a single frame of the game scene into the buffer.
 * @param ctx The render context.
 */
void				render_frame(t_renderctx *ctx);

/*
 * @brief Presents the rendered frame from the buffer to the window.
 * @param ctx The render context.
 */
void				render_present(t_renderctx *ctx);

/*
 * @brief Frees all resources associated with the render context.
 * @param ctx The render context to free.
 */
void				render_free(t_renderctx *ctx);
