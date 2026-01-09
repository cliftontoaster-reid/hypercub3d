/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:40:50 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/09 15:14:59 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/image.h"
#include "graphics/render.h"
#include "map/minimap.h"
#include "mlx.h"

static int	close_window_worse(void *stuff)
{
	close_window(stuff);
	return (69420);
}

void	init_window(t_renderctx *render)
{
	display_minimap(render);
	render->keyboard = keyboard_init(render->mlx, render->win);
	render->mouse = mouse_init(render->mlx, render->win);
	mlx_mouse_hide(render->mlx, render->win);
	keyboard_on_press(render->keyboard, XK_Escape, close_window, render);
	mlx_hook(render->win, 17, 1L << 17, close_window_worse, render);
	mlx_loop_hook(render->mlx, render_update_lone, render);
	mlx_loop(render->mlx);
}

static int	create_windows(t_renderctx *ctx, t_vec2i win_size)
{
	if (!ctx->mlx)
		return (-1);
	ctx->win = mlx_new_window(ctx->mlx, win_size.x, win_size.y, "HyperCub3D");
	if (!ctx->win)
		return (-1);
	return (0);
}

static int	create_buffers(t_renderctx *ctx, t_vec2i win_size)
{
	ctx->buffer = image_new(ctx->mlx, win_size.x, win_size.y);
	if (!ctx->buffer)
	{
		return (-1);
	}
	return (0);
}

t_renderctx	*render_init(t_table *map, t_vec2i win_size, void *mlx)
{
	t_renderctx	*ctx;

	ctx = malloc(sizeof(t_renderctx));
	if (!ctx)
		return (NULL);
	ft_bzero(ctx, sizeof(t_renderctx));
	ctx->map = map;
	ctx->mlx = mlx;
	ctx->pos.x = (float)map->player_pos.x + 0.5f;
	ctx->pos.y = (float)map->player_pos.y + 0.5f;
	ctx->dir = map->player_dir;
	if (create_windows(ctx, win_size) != 0)
	{
		render_free(ctx);
		return (NULL);
	}
	if (create_buffers(ctx, win_size) != 0)
	{
		render_free(ctx);
		return (NULL);
	}
	init_window(ctx);
	return (ctx);
}
