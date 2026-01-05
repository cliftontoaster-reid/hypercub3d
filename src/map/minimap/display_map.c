/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:55:20 by mbores            #+#    #+#             */
/*   Updated: 2026/01/05 11:23:58 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/colour.h"
#include "map/minimap.h"

void	put_pixels_in_square(t_image *img, t_colour color, int x, int y)
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

void	put_squares_on_map(t_holy_cow *all)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < all->map->height)
	{
		while (x < all->map->width)
		{
			if (all->map->cells[y][x] == '0')
				put_pixels_in_square(all->window->image, rgb(225, 193, 110), x,
					y);
			else if (all->map->cells[y][x] == '1')
				put_pixels_in_square(all->window->image, rgb(255, 255, 143), x,
					y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	display_map(t_holy_cow *all)
{
	put_squares_on_map(all);
	mlx_put_image_to_window(all->window->mlx, all->window->mlx_win,
		all->window->image->img_ptr, 0, 0);
}
