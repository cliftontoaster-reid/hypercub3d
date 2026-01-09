/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:48:16 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/09 16:11:24 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/render.h"
#include "mlx.h"
#include <math.h>
#include <stdbool.h>
#include <time.h>

#ifndef CLOCK_MONOTONIC
# define CLOCK_MONOTONIC 1
#endif

int	render_update_lone(t_renderctx *ctx)
{
	struct timespec	current_time;
	struct timespec	wait_time;
	float			delta_time_sec;

	clock_gettime(CLOCK_MONOTONIC, &current_time);
	delta_time_sec = (current_time.tv_sec - ctx->last_frame_time.tv_sec)
		+ (current_time.tv_nsec - ctx->last_frame_time.tv_nsec) / 1000000000.0f;
	ctx->last_frame_time = current_time;
	image_clear(ctx->buffer, rgb(0, 0, 0));
	render_update(ctx, delta_time_sec);
	render_frame(ctx);
	render_present(ctx);
	// wait 16ms
	while (true)
	{
		clock_gettime(CLOCK_MONOTONIC, &current_time);
		wait_time.tv_sec = current_time.tv_sec - ctx->last_frame_time.tv_sec;
		wait_time.tv_nsec = current_time.tv_nsec - ctx->last_frame_time.tv_nsec;
		if (wait_time.tv_nsec < 0)
		{
			wait_time.tv_sec -= 1;
			wait_time.tv_nsec += 1000000000;
		}
		if (wait_time.tv_sec > 0 || wait_time.tv_nsec >= 16000000)
			break ;
	}
	return (0);
}

#ifdef COLLISION

static bool	can_move(t_renderctx *ctx, t_vec2 *new_pos)
{
	(void)ctx;
	(void)new_pos;
	ft_printf("Collision detection not implemented yet.\n");
	abort();
}

#else

static bool	can_move(t_renderctx *ctx, t_vec2 *new_pos)
{
	int	new_cell_x;
	int	new_cell_y;

	new_cell_x = (int)(new_pos->x);
	new_cell_y = (int)(new_pos->y);
	if (new_cell_x < 0 || new_cell_x >= (int)ctx->map->width || new_cell_y < 0
		|| new_cell_y >= (int)ctx->map->height)
		return (false);
	return (true);
}

#endif

static void	update_position(t_renderctx *ctx, float move_dst)
{
	t_vec2	delta;
	t_vec2	rotated_delta;
	t_vec2	new_pos;
	float	cos_dir;
	float	sin_dir;

	delta = vec2_new(0.0f, 0.0f);
	if (keyboard_is_pressed(ctx->keyboard, XK_w))
		delta.y += move_dst;
	if (keyboard_is_pressed(ctx->keyboard, XK_s))
		delta.y -= move_dst;
	if (keyboard_is_pressed(ctx->keyboard, XK_a))
		delta.x -= move_dst;
	if (keyboard_is_pressed(ctx->keyboard, XK_d))
		delta.x += move_dst;
	cos_dir = cosf(ctx->dir);
	sin_dir = sinf(ctx->dir);
	rotated_delta.x = delta.x * cos_dir + delta.y * sin_dir;
	rotated_delta.y = delta.x * sin_dir - delta.y * cos_dir;
	new_pos = vec2_add(ctx->pos, rotated_delta);
	if (can_move(ctx, &new_pos))
		ctx->pos = new_pos;
}

static void	update_rotation(t_renderctx *ctx, float rot_angle)
{
	t_vec2i	current_pos;
	t_vec2i	center_pos;
	t_vec2	delta;

	if (keyboard_is_pressed(ctx->keyboard, XK_Left)
		|| keyboard_is_pressed(ctx->keyboard, XK_q))
		ctx->dir -= rot_angle;
	if (keyboard_is_pressed(ctx->keyboard, XK_Right)
		|| keyboard_is_pressed(ctx->keyboard, XK_e))
		ctx->dir += rot_angle;
	center_pos = v2i(ctx->buffer->width / 2, ctx->buffer->height / 2);
	mlx_mouse_get_pos(ctx->mlx, ctx->win, &current_pos.x, &current_pos.y);
	delta.x = (float)(current_pos.x - center_pos.x);
	delta.y = (float)(current_pos.y - center_pos.y);
	ctx->dir += delta.x * 0.002f;
	mlx_mouse_move(ctx->mlx, ctx->win, center_pos.x, center_pos.y);
}

void	render_update(t_renderctx *ctx, float delta_time)
{
	float	move_speed;
	float	rot_angle;

	move_speed = 0.2f;
	rot_angle = 0.05f;
	update_position(ctx, move_speed * delta_time);
	update_rotation(ctx, rot_angle);
}
