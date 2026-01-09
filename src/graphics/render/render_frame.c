/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:40:20 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/09 16:20:06 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/image.h"
#include "graphics/render.h"
#include "map/minimap.h"

static t_image	*get_texture(t_renderctx *ctx, t_rayhit *ray)
{
	/* Bounds check before accessing array */
	if (ray->hit_map.x < 0 || ray->hit_map.x >= (int)ctx->map->width
		|| ray->hit_map.y < 0 || ray->hit_map.y >= (int)ctx->map->height)
		return (NULL);
	if (ctx->map->cells[ray->hit_map.y][ray->hit_map.x] == '1')
	{
		if (ray->hit_side == RAY_SIDE_NORTH)
			return (ctx->map->no_wall);
		if (ray->hit_side == RAY_SIDE_SOUTH)
			return (ctx->map->so_wall);
		if (ray->hit_side == RAY_SIDE_EAST)
			return (ctx->map->ea_wall);
		if (ray->hit_side == RAY_SIDE_WEST)
			return (ctx->map->we_wall);
	}
	return (NULL);
}

static void	error_column(t_renderctx *ctx, int x)
{
	int	y;

	y = 0;
	while (y < ctx->buffer->height)
	{
		image_put_pixel(ctx->buffer, x, y, 0xFF00FF);
		y++;
	}
}

static void	render_column(t_renderctx *ctx, int x, t_raycast *ray)
{
	t_image		*texture;
	t_rayhit	hit;
	float		scale;
	int			col_x;

	raycast_dda(ctx, ray, ctx->map->cells, &hit);
	/* reject invalid results (NaN/inf) and very small distances that
		would make the wall take more than the whole screen */
	if (!ray->hit || hit.hit_side == RAY_SIDE_NONE || !isfinite(hit.dist)
		|| hit.dist <= 1e-4f)
	{
		error_column(ctx, x);
		return ;
	}
	texture = get_texture(ctx, &hit);
	if (!texture)
	{
		error_column(ctx, x);
		return ;
	}
	/* compute scale as reciprocal distance; very close walls will produce
		scale > 1, which we handle in image_blit_col by clamping */
	scale = 1 / hit.dist;
	col_x = (int)floorf(hit.hit_pos * (float)(texture->width));
	image_blit_col(ctx->buffer, texture, vec2i_new(col_x, x), scale);
}

void	render_frame(t_renderctx *ctx)
{
	int			i;
	t_raycast	ray;

	i = 0;
	while (i < ctx->buffer->width)
	{
		ray = raycast_from_ctx(ctx, i);
		render_column(ctx, i, &ray);
		i++;
	}
	// Render minimap
	display_minimap(ctx);
}
