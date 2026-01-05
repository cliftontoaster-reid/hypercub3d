/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_put_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:03:53 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/05 11:03:55 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "graphics/image.h"

void	image_put_pixel(t_image *img, int x, int y, int color)
{
	unsigned char	*dst;

	if (!img || !img->addr)
		return;
	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return;
	dst = (unsigned char *)(img->addr + (y * img->lln + x * (img->bpp / 8)));
	dst[0] = (color) & 0xFF;
	dst[1] = (color >> 8) & 0xFF;
	dst[2] = (color >> 16) & 0xFF;
	if (img->bpp == 32)
		dst[3] = (color >> 24) & 0xFF;
}
