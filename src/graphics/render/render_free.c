/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:45:43 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/08 12:55:53 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/render.h"
#include "mlx.h"

void	render_free(t_renderctx *ctx)
{
	if (!ctx)
		return ;
	if (ctx->buffer_game)
		image_free(ctx->buffer_game);
	if (ctx->buffer_minimap)
		image_free(ctx->buffer_minimap);
	if (ctx->win_game)
		mlx_destroy_window(ctx->mlx, ctx->win_game);
	if (ctx->win_minimap)
		mlx_destroy_window(ctx->mlx, ctx->win_minimap);
	free(ctx);
}
