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

static void	setup_ray_direction(t_raycast *ray, t_vec2 player_dir, t_vec2 plane,
		int x, int screen_width)
{
	double	camera_x;

	camera_x = 2 * x / (double)screen_width - 1;
	ray->ray_dir.x = player_dir.x + plane.x * camera_x;
	ray->ray_dir.y = player_dir.y + plane.y * camera_x;
}

static void	setup_delta_distances(t_raycast *ray)
{
	ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
}

static void	setup_x_step(t_raycast *ray, t_renderctx *ctx)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (ctx->pos.x - ray->map_pos.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map_pos.x + 1.0 - ctx->pos.x)
			* ray->delta_dist.x;
	}
}

static void	setup_y_step(t_raycast *ray, t_renderctx *ctx)
{
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (ctx->pos.y - ray->map_pos.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map_pos.y + 1.0 - ctx->pos.y)
			* ray->delta_dist.y;
	}
}

t_raycast	raycast_from_ctx(t_renderctx *ctx, int x)
{
	t_raycast	ray;
	t_vec2		camera_plane;
	float		plane_len;
	float		dir_x;
	float		dir_y;
	t_vec2		player_dir;

	plane_len = tan(render_fov_rad() / 2.0f);
	/* compute player direction vector from angle */
	{
		/* rotate by -90 degrees to match map's player_dir convention */
		dir_x = cosf(ctx->dir - ((float)M_PI / 2.0f));
		dir_y = sinf(ctx->dir - ((float)M_PI / 2.0f));
		player_dir = vec2_new(dir_x, dir_y);
		camera_plane = vec2_scale(vec2_new(-player_dir.y, player_dir.x),
				plane_len);
		ray.player_pos = ctx->pos;
		ray.map_pos = v2i((int)ctx->pos.x, (int)ctx->pos.y);
		ray.hit = false;
		ray.map_table = ctx->map;
		ray.fisheye_correction = true;
		setup_ray_direction(&ray, player_dir, camera_plane, x,
			ctx->buffer->width);
		setup_delta_distances(&ray);
		setup_x_step(&ray, ctx);
		setup_y_step(&ray, ctx);
		return (ray);
	}
}
