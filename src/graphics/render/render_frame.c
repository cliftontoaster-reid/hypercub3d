/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:40:20 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/09 14:26:28 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/render.h"
#include "map/minimap.h"

static t_image	*get_texture(t_renderctx *ctx, t_rayhit *ray)
{
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

static void	render_column(t_renderctx *ctx, int x, t_raycast *ray)
{
	t_image		*texture;
	t_rayhit	hit;

	raycast_dda(ctx, ray, ctx->map->cells, &hit);
	texture = get_texture(ctx, &hit);
	(void)texture;
	(void)x;
	(void)ray;
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
