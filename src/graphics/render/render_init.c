/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:40:50 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/05 12:47:18 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/image.h"
#include "graphics/render.h"
#include "mlx.h"

t_renderctx	*render_init(t_table *map, void *mlx, t_vec2i win_size)
{
	t_renderctx	*ctx;

	ctx = malloc(sizeof(t_renderctx));
	if (!ctx)
		return (NULL);
	ft_bzero(ctx, sizeof(t_renderctx));
	ctx->map = map;
	ctx->mlx = mlx;
	ctx->win = mlx_new_window(mlx, win_size.x, win_size.y, "HyperCub3D");
	if (!ctx->win)
	{
		free(ctx);
		return (NULL);
	}
	ctx->buffer = image_new(mlx, win_size.x, win_size.y);
	if (!ctx->buffer)
	{
		mlx_destroy_window(mlx, ctx->win);
		free(ctx);
		return (NULL);
	}
	return (ctx);
}
