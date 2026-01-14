/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:42:10 by mbores            #+#    #+#             */
/*   Updated: 2026/01/14 12:59:39 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/colour.h"
#include "map/minimap.h"

static void	put_pix_in_sq(t_image *img, t_colour color, int x, int y)
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
	px = (int)((x - 0.5) * 32);
	py = (int)((y - 0.5) * 32);
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
	size_t	v[4];

	v[0] = minimap_x;
	v[1] = minimap_y;
	v[2] = 0;
	v[3] = 0;
	while (v[3] < 9 && v[1] < all->map->height)
	{
		while (v[2] < 9 && v[0] < all->map->width)
		{
			if (all->map->cells[v[1]][v[0]] == '2')
				break ;
			if (all->map->cells[v[1]][v[0]] == '0')
				put_pix_in_sq(all->buffer, all->map->floor_col, v[2], v[3]);
			else if (all->map->cells[v[1]][v[0]] == '1')
				put_pix_in_sq(all->buffer, rgb(0, 0, 0), v[2], v[3]);
			v[0]++;
			v[2]++;
		}
		v[2] = 0;
		v[0] = minimap_x;
		v[1]++;
		v[3]++;
	}
	player_square(all, (player_pos.x - minimap_x), (player_pos.y - minimap_y));
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
