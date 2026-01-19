/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_from_ctx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:49:01 by mbores           #+#    #+#             */
/*   Updated: 2026/01/08 14:49:01 by mbores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/render.h"
#include <math.h>

static t_vec2	get_camera_plane(t_vec2 dir)
{
	float	len;

	len = tan(render_fov_rad() / 2.0f);
	return (vec2_scale(vec2_new(-dir.y, dir.x), len));
}

static void	init_ray(t_raycast *ray, t_renderctx *ctx)
{
	ray->player_pos = ctx->pos;
	ray->map_pos = v2i((int)ctx->pos.x, (int)ctx->pos.y);
	ray->hit = false;
	ray->map_table = ctx->map;
	ray->fisheye_correction = true;
}

static float	safe_inv(float v)
{
	if (fabs(v) < 1e-8)
		return (1e30);
	return (fabs(1.0 / v));
}

static void	setup_delta_distances(t_raycast *ray)
{
	ray->delta_dist.x = safe_inv(ray->ray_dir.x);
	ray->delta_dist.y = safe_inv(ray->ray_dir.y);
}

t_raycast	raycast_from_ctx(t_renderctx *ctx, int x)
{
	t_raycast	ray;
	t_vec2		player_dir;
	t_vec2		camera_plane;
	t_ray_setup	setup;

	player_dir = get_player_dir(ctx->dir);
	camera_plane = get_camera_plane(player_dir);
	init_ray(&ray, ctx);
	setup.player_dir = player_dir;
	setup.plane = camera_plane;
	setup.x = x;
	setup.screen_width = ctx->buffer->width;
	setup_ray_direction(&ray, &setup);
	setup_delta_distances(&ray);
	setup_x_step(&ray, ctx);
	setup_y_step(&ray, ctx);
	return (ray);
}

// t_raycast	raycast_from_ctx(t_renderctx *ctx, int x)
// {
// 	t_raycast	ray;
// 	t_vec2		camera_plane;
// 	float		plane_len;
// 	float		dir_x;
// 	float		dir_y;
// 	t_vec2		player_dir;

// 	plane_len = tan(render_fov_rad() / 2.0f);
// 	{
// 		dir_x = cosf(ctx->dir - ((float)M_PI / 2.0f));
// 		dir_y = sinf(ctx->dir - ((float)M_PI / 2.0f));
// 		player_dir = vec2_new(dir_x, dir_y);
// 		camera_plane = vec2_scale(vec2_new(-player_dir.y, player_dir.x),
// 				plane_len);
// 		ray.player_pos = ctx->pos;
// 		ray.map_pos = v2i((int)ctx->pos.x, (int)ctx->pos.y);
// 		ray.hit = false;
// 		ray.map_table = ctx->map;
// 		ray.fisheye_correction = true;
// 		setup_ray_direction(&ray, player_dir, camera_plane, x,
// 			ctx->buffer->width);
// 		setup_delta_distances(&ray);
// 		setup_x_step(&ray, ctx);
// 		setup_y_step(&ray, ctx);
// 		return (ray);
// 	}
// }
