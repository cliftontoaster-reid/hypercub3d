/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:45:43 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/09 14:52:53 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/render.h"
#include "mlx.h"

void	render_free(t_renderctx *ctx)
{
	if (!ctx)
		return ;
	if (ctx->buffer)
		image_free(ctx->buffer);
	if (ctx->win)
		mlx_destroy_window(ctx->mlx, ctx->win);
	if (ctx->mlx)
		mlx_destroy_display(ctx->mlx);
	if (ctx->map)
		table_free(ctx->map);
	if (ctx->keyboard)
		keyboard_free(ctx->keyboard);
	if (ctx->mouse)
		free(ctx->mouse);
	free(ctx);
}
