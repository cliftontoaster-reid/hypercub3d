/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:44:25 by mbores            #+#    #+#             */
/*   Updated: 2025/12/22 15:13:48 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/minimap.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (!img || !img->addr)
		return;
	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return;	
	dst = img->addr + (y * img->lln + x * (img->bpp / 8));
	dst[0] = (color) & 0xFF;
	dst[1] = (color >> 8) & 0xFF;
	dst[2] = (color >> 16) & 0xFF;
	if (img->bpp == 32)
		dst[3] = (color >> 24) & 0xFF;
}