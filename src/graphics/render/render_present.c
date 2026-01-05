/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_present.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:46:00 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/05 12:46:43 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/render.h"
#include "mlx.h"

inline void	render_present(t_renderctx *ctx)
{
	mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->buffer->addr, 0, 0);
}
