/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:45:43 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/05 12:53:48 by lfiorell         ###   ########.fr       */
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
	free(ctx);
}
