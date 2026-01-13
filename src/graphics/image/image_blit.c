/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_blit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:51:44 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/13 15:05:06 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/image.h"

static void	blit_pixel(t_blit_ctx *ctx, int x, int y)
{
	int	src_x;
	int	src_y;
	int	color;

	src_x = ctx->pos->src_pos.x + x;
	src_y = ctx->pos->src_pos.y + y;
	if (src_x < 0 || src_y < 0
		|| src_x >= ctx->src->width
		|| src_y >= ctx->src->height)
		return ;
	color = image_get_pixel(ctx->src, src_x, src_y);
	image_put_pixel(ctx->dest,
		ctx->pos->dest_pos.x + x,
		ctx->pos->dest_pos.y + y,
		color);
}

void	image_blit(t_image *dest, t_image *src, t_pos *pos)
{
	t_blit_ctx	ctx;
	int			x;
	int			y;

	if (!dest || !src || !pos)
		return ;
	ctx.dest = dest;
	ctx.src = src;
	ctx.pos = pos;
	y = 0;
	while (y < pos->size.y)
	{
		x = 0;
		while (x < pos->size.x)
			blit_pixel(&ctx, x++, y);
		y++;
	}
}
