/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:42:10 by mbores            #+#    #+#             */
/*   Updated: 2026/01/09 16:45:41 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/colour.h"
#include "map/minimap.h"

static void	put_pixels_in_square(t_image *img, t_colour color, int x, int y)
{
	int	xx;
	int	yy;

	xx = 0;
	yy = 0;
	while (yy < 32)
	{
		while (xx < 32)
		{
			image_put_pixel(img, (x * 32) + xx, (y * 32) + yy, c(color));
			xx++;
		}
		xx = 0;
		yy++;
	}
}

static void	player_square(t_renderctx *ctx, float x, float y)
{
	int	xx;
	int	yy;
	int	px;
	int	py;

	xx = 0;
	yy = 0;
	px = (int)x;
	py = (int)y;
	while (yy < 5)
	{
		while (xx < 5)
		{
			image_put_pixel(ctx->buffer, px + 13 + xx, py + 13 + yy, c(rgb(255,
						0, 0)));
			xx++;
		}
		xx = 0;
		yy++;
	}
}

static void	put_squares_on_map(t_renderctx *all, int minimap_x, int minimap_y,
		t_vec2 player_pos)
{
	size_t	x;
	size_t	y;
	size_t	i;
	size_t	j;
	float	player_px;
	float	player_py;

	x = minimap_x;
	y = minimap_y;
	i = 0;
	j = 0;
	player_px = ((player_pos.x - minimap_x) - 0.5) * 32;
	player_py = ((player_pos.y - minimap_y) - 0.5) * 32;
	while (j < 9 && y < all->map->height)
	{
		while (i < 9 && x < all->map->width)
		{
			if (all->map->cells[y][x] == '0')
				put_pixels_in_square(all->buffer, rgb(225, 193, 110), i, j);
			else if (all->map->cells[y][x] == '1')
				put_pixels_in_square(all->buffer, rgb(255, 255, 143), i, j);
			x++;
			i++;
		}
		i = 0;
		x = minimap_x;
		y++;
		j++;
	}
	player_square(all, player_px, player_py);
}

void	display_minimap(t_renderctx *ctx)
{
	int	minimap_x;
	int	minimap_y;

	minimap_x = (int)(ctx->pos.x - 4.5);
	if (minimap_x < 0)
		minimap_x = 0;
	minimap_y = (int)(ctx->pos.y - 4.5);
	if (minimap_y < 0)
		minimap_y = 0;
	put_squares_on_map(ctx, minimap_x, minimap_y, ctx->pos);
	render_present(ctx);
}
