/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_get_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:03:39 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/05 11:03:43 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "graphics/image.h"

int	image_get_pixel(t_image *img, int x, int y)
{
	unsigned char	*dst;
	int			color;

	if (!img || !img->addr)
		return (0);
	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return (0);
	dst = (unsigned char *)(img->addr + (y * img->lln + x * (img->bpp / 8)));
	color = dst[0] | (dst[1] << 8) | (dst[2] << 16);
	if (img->bpp == 32)
		color |= (dst[3] << 24);
	return (color);
}
