/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_blit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:51:44 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/09 15:56:02 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/image.h"

static void	blit_pixel(t_image *dest, t_image *src, t_pos *pos, int x, int y)
{
	int	src_x;
	int	src_y;
	int	color;

	src_x = pos->src_pos.x + x;
	src_y = pos->src_pos.y + y;
	if (src_x >= 0 && src_x < src->width && src_y >= 0 && src_y < src->height)
	{
		color = image_get_pixel(src, src_x, src_y);
		image_put_pixel(dest, pos->dest_pos.x + x, pos->dest_pos.y + y, color);
	}
}

void	image_blit(t_image *dest, t_image *src, t_pos *pos)
{
	int	x;
	int	y;

	if (!dest || !src || !pos)
		return ;
	y = 0;
	while (y < pos->size.y)
	{
		x = 0;
		while (x < pos->size.x)
		{
			blit_pixel(dest, src, pos, x, y);
			x++;
		}
		y++;
	}
}
