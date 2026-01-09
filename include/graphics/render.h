/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:28:25 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/09 15:15:18 by lfiorell         ###   ########.fr       */
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
#include <time.h>

#define RAYCAST_MAX_RAYS 2160
#define RENDER_FOV_DEG 66.0f
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

/**
 * @brief Converts the field of view from degrees to radians.
 * @return The field of view in radians.
 */
static inline float	render_fov_rad(void)
{
	return (RENDER_FOV_DEG * (float)M_PI / 180.0f);
}

/**
 * @struct s_rendertiming
 * @brief Holds timing information for rendering, used for performance metrics.
 *
 * This structure tracks various timings such as average, min, and max time
 * per ray, total time for all rays, and image rendering time. It also stores
 * raw timing data for each ray in the last frame for detailed analysis.
 */
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

/**
 * @struct s_renderctx
 * @brief The main rendering context for the application.
 *
 * This structure holds all the necessary components for rendering the game,
 * including image buffers, map data, player state (position and direction),
 * MLX pointers for window management, and input states for keyboard and mouse.
 * It also includes a debug flag and timing information.
 */
typedef struct s_renderctx
{
	t_image			*buffer;

	t_table			*map;
	t_vec2			pos;
	float			dir;

	void			*mlx;
	void			*win;

	t_key_state		*keyboard;
	t_mouse_state	*mouse;

	bool			debug_mode;
	t_rendertiming	timing;
	struct timespec	last_frame_time;
}					t_renderctx;

/*
 * @brief Initializes the render context, setting up the image buffer
 *        and window.
 * @param map The game map.
 * @param mlx The Minilibx instance.
 * @param win_size The size of the window.
 * @param mlx The MLX instance pointer.
 * @return The initialized render context if successful, NULL otherwise.
 */
t_renderctx			*render_init(t_table *map, t_vec2i win_size, void *mlx);

/*
 * @brief Updates the player's movement and rotation based on input.
 * @param ctx The render context containing player and input states.
 * @param delta_time The time elapsed since the last frame,
 *        for frame-rate independent movement.
 */
void				render_update(t_renderctx *ctx, float delta_time);
int					render_update_lone(t_renderctx *ctx);

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

/*
 * @brief Adds a raycast timing sample to the render timing statistics.
 *
 * This is used for performance monitoring and debugging.
 *
 * @param t The render timing statistics.
 * @param time The time taken by the raycast.
 */
void				rendertiming_add_ray(t_rendertiming *t, double time);

/*
 * @brief Sets the total time taken by all raycasts in the last frame.
 *
 * This is used for performance monitoring and debugging.
 *
 * @param t The render timing statistics.
 * @param time The total time for all raycasts.
 */
void				rendertiming_set_all_rays(t_rendertiming *t, double time);

/*
 * @brief Sets the time taken to render the image.
 *
 * This does not include the time taken for raycasting.
 * This is used for performance monitoring and debugging.
 *
 * @param t The render timing statistics.
 * @param time The time taken to render the image.
 */
void				rendertiming_set_render(t_rendertiming *t, double time);

/*
 * @brief Resets the render timing statistics for the next frame.
 * @param timing The render timing statistics to reset.
 */
void				rendertiming_reset(t_rendertiming *timing);

#ifdef DEBUG

/*
 * @brief Renders a debug timeline of the rendering process.
 *
 * This helps visualize the time taken by different parts of the rendering.
 *
 * @param ctx The render context.
 */
void				render_debug_timeline(t_renderctx *ctx);

/*
 * @brief Renders the raycast rays on the minimap for debugging.
 * @param ctx The render context.
 * @param minimap The minimap image to draw on.
 */
void				render_debug_rays(t_renderctx *ctx, t_image *minimap);

/*
 * @brief Renders player information on the minimap for debugging.
 *
 * This can include position, direction, etc.
 *
 * @param ctx The render context.
 * @param minimap The minimap image to draw on.
 */
void				render_debug_player(t_renderctx *ctx, t_image *minimap);

#endif
