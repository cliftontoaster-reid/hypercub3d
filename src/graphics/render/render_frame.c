/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:40:20 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/13 12:36:48 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/colour.h"
#include "graphics/image.h"
#include "graphics/render.h"
#include "map/minimap.h"

static t_image	*get_texture(t_renderctx *ctx, t_rayhit *ray)
{
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

static void	fill_ceiling_floor(t_renderctx *ctx, int x, float scale)
{
	int		rendered_height;
	int		start_y;
	int		y;
	int		ceiling_color;
	int		floor_color;

	rendered_height = (int)(scale * (float)ctx->buffer->height);
	if (rendered_height >= ctx->buffer->height)
		return ;
	start_y = (ctx->buffer->height - rendered_height) / 2;
	ceiling_color = c(ctx->map->ceil_col);
	floor_color = c(ctx->map->floor_col);
	y = 0;
	while (y < start_y)
	{
		image_put_pixel(ctx->buffer, x, y, ceiling_color);
		y++;
	}
	y = start_y + rendered_height;
	while (y < ctx->buffer->height)
	{
		image_put_pixel(ctx->buffer, x, y, floor_color);
		y++;
	}
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
	scale = 1 / hit.dist;
	col_x = (int)floorf(hit.hit_pos * (float)(texture->width));
	image_blit_col(ctx->buffer, texture, vec2i_new(col_x, x), scale);
	fill_ceiling_floor(ctx, x, scale);
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
	display_minimap(ctx);
}
