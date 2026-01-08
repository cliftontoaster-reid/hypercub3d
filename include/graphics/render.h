/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:28:25 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/06 15:38:04 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "graphics/image.h"
#include "graphics/raycast.h"
#include "hooks/peterpan.h"
#include "libft.h"
#include "map/table.h"
#include <math.h>
#include <stdbool.h>
#include <stddef.h>

#define RAYCAST_MAX_RAYS 2160
#define RENDER_FOV_DEG 66.0f

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

inline float	render_fov_rad(void)
{
	return (RENDER_FOV_DEG * (float)M_PI / 180.0f);
}

typedef struct s_rendertiming
{
	/* average time per ray (in microseconds) */
	double			per_ray_avg;
	/* max time observed for a single ray */
	double			per_ray_max;
	/* min time observed for a single ray */
	double			per_ray_min;
	/* total time taken by all rays in the last batch */
	double			all_rays;
	/* time taken to render the image (in microseconds) */
	double			image_render;
	/* number of per-ray samples used to compute avg */
	size_t			samples;
	/* the raw ray times for the last frame */
	double			ray_times[RAYCAST_MAX_RAYS];
	/* the next index to write a ray time to */
	size_t			next_ray_index;
}					t_rendertiming;

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

	bool			debug_mode;
	t_rendertiming	timing;
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

/*
 * @brief Renders debug information (like raycast lines) onto the buffer.
 * @param ctx The render context.
 *
 * This prints information like
 *
 * - Raycast results
 * - Player position, direction and movement vectors
 * - The time it took to render the last frame, with detailed breakdowns
 * - etc.
 */
void				render_debug(t_renderctx *ctx);
void				rendertiming_add_ray(t_rendertiming *t, double time);
void				rendertiming_set_all_rays(t_rendertiming *t, double time);
void				rendertiming_set_render(t_rendertiming *t, double time);
void				rendertiming_reset(t_rendertiming *timing);

#ifdef DEBUG

void				render_debug_timeline(t_renderctx *ctx);
void				render_debug_rays(t_renderctx *ctx, t_image *minimap);
void				render_debug_player(t_renderctx *ctx, t_image *minimap);

#endif
