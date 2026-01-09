/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_present.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:46:00 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/08 12:55:38 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/render.h"
#include "mlx.h"

inline void	render_present(t_renderctx *ctx)
{
	mlx_put_image_to_window(ctx->mlx, ctx->win_game, ctx->buffer_game->img_ptr,
		0, 0);
	mlx_put_image_to_window(ctx->mlx, ctx->win_minimap,
		ctx->buffer_minimap->img_ptr, 0, 0);
}
