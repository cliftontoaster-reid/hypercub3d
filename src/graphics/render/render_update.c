/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:48:16 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/06 15:02:29 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/render.h"
#include "mlx.h"
#include <math.h>
#include <stdbool.h>

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
		delta.x += move_dst;
	if (keyboard_is_pressed(ctx->keyboard, XK_s))
		delta.x -= move_dst;
	if (keyboard_is_pressed(ctx->keyboard, XK_a))
		delta.y += move_dst;
	if (keyboard_is_pressed(ctx->keyboard, XK_d))
		delta.y -= move_dst;
	cos_dir = cosf(*ctx->dir);
	sin_dir = sinf(*ctx->dir);
	rotated_delta.x = delta.x * cos_dir - delta.y * sin_dir;
	rotated_delta.y = delta.x * sin_dir + delta.y * cos_dir;
	new_pos = vec2_add(*ctx->pos, rotated_delta);
	if (can_move(ctx, &new_pos))
		*ctx->pos = new_pos;
}

static void	update_rotation(t_renderctx *ctx, float rot_angle)
{
	t_vec2	mouse_delta;

	if (keyboard_is_pressed(ctx->keyboard, XK_Left)
		|| keyboard_is_pressed(ctx->keyboard, XK_q))
		*ctx->dir -= rot_angle;
	if (keyboard_is_pressed(ctx->keyboard, XK_Right)
		|| keyboard_is_pressed(ctx->keyboard, XK_e))
		*ctx->dir += rot_angle;
	mouse_delta = mouse_get_delta(ctx->mouse);
	*ctx->dir += mouse_delta.x * 0.002f;
	mouse_reset_delta(ctx->mouse, ctx->mlx, ctx->win, v2i(ctx->buffer->width,
			ctx->buffer->height));
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
